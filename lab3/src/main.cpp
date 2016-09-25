
#include "adc.h"
#include "master_adc.cpp"
#include "slave_adc.cpp"

SCA_TDF_MODULE(drain) {
	sca_tdf::sca_in<sc_bv<16> > in;
	sca_tdf::sca_out<double> out;
		SCA_CTOR(drain) {
		}
};

SC_MODULE(Top)
{
  Master_ADC *master;
  Slave_ADC  *slave;

	//sc_out<int> channel_selector_top;

	sc_signal<int> channel_selector_slv;

  SC_CTOR(Top)
  {
    // Instantiate components
    master = new Master_ADC("initiator");
    slave  = new Slave_ADC("memory");

    // One initiator is bound directly to one target with no intervening bus
    // Bind initiator socket to target socket
	  cout << endl << "Binding TLM socket..." << endl;
    master->socket.bind( slave->socket );

	  cout << endl << "Testing functions..." << endl;
		master->ADC_Configuration(ADC_BASE_ADDR + ADC_MR, "FFFFFFFF");
		master->ADC_Configuration(ADC_BASE_ADDR + ADC_COR, "BBBBBBBB");
		master->ADC_GetStatus();
		master->ADC_GetData(1);
		master->ADC_GetData(3);
		master->ADC_GetData(5);
		master->ADC_GetData(7);
  }
};

int sc_main(int argc, char* argv[])
{
	sc_signal<int> mux_sel;

  Top top("top");
	drain drn("drn");

	// Inputs
	sca_tdf::sca_signal<double> AD3;
	sca_tdf::sca_signal<double> AD5;
	sca_tdf::sca_signal<double> AD7;
	sca_tdf::sca_signal<int> ADTRG;    // external trigger
	sca_tdf::sca_signal<int> ADVREF;  // ref voltages
	sca_tdf::sca_signal<int> GND;

	sca_tdf::sca_signal<double> offset_to_pga;
//	sca_tdf::sca_signal<double> multiplexed_input;
	sca_tdf::sca_signal<double> pga_to_adc;
	sca_tdf::sca_signal<sc_bv<16>> adc_to_reg;


	sca_tdf::sca_signal<double> freq_val_tdf;

	drn.out(freq_val_tdf);

	// Sine wave with 2V amplitude
	sine Sine("Sine", 0, 2, 0.0, 0.0, false, true, 1); // (amp_c and freq_c are false)
	Sine.set_timestep(10, sc_core::SC_US); // Time step (sampling rate) of port "out" = 10 us
	Sine.freq_con(&freq_val_tdf); // need this as port to vary the frequency through tlm interface
	Sine.out(AD3);

	// Cos -- sin phase shifted with 2.5V amplitude
	sine Cos("Cos", 0, 2.5, 3.14, 0.0, false, true, 1); // (amp_c and freq_c are false)
	Cos.set_timestep(10, sc_core::SC_US); // Time step (sampling rate) of port "out" = 10 us
	Cos.freq_con(&freq_val_tdf); // need this as port to vary the frequency through tlm interface
	Cos.out(AD5);

	// Saw tooth with 2.5V amplitude - saw_gen(sc_core::sc_module_name n, double freq,double _amp, double _ofs=0.0, int d_rate=1);
	saw_gen Saw("Saw", 0, 2.5, 0.0, 1); // (amp_c and freq_c are false)
	Saw.set_timestep(10, sc_core::SC_US);
	Saw.out(AD7);

	// OFFSET
	add_offset<double> offset("offset",4);// instance the offset

	// Mux based on ADC_CHSR - channel status register
	switch (mux_sel){
		case 3: offset.in(AD3); break;
		case 5: offset.in(AD5); break;
		case 7: offset.in(AD7); break;
		default: offset.in(AD3); break;
	}

	//offset.in(multiplexed_input);
	offset.out(offset_to_pga);

	// PGA
	amp<double> ampl("ampl",10); // instance the amplifer
	ampl.in(offset_to_pga);
	ampl.out(pga_to_adc);
//#include <ref_src.h>

	// 12 bit adc converter
	//	adc(sc_core::sc_module_name n, double uref=1.0, double gain_e=0.0, double offset_e=0.0, int nl_m=0)
	adc<16> i_adc("adc", 2, 0.0, 0.0);  //use default parameters
	i_adc.in(pga_to_adc);
	i_adc.out(adc_to_reg);

	// This is only a module used to consume tokens as we can not let a
	// systemc-ams scheduling loop open.
	drn.in(adc_to_reg);


	// Trace analog inputs and resulting digital values for each channel
	sca_util::sca_trace_file* atf = sca_util::sca_create_vcd_trace_file("tr");
	sca_util::sca_trace(atf, AD3, "AD3");
	sca_util::sca_trace(atf, AD5, "AD5");
	sca_util::sca_trace(atf, AD7, "AD7");

	sca_util::sca_trace_file* tfp_tab = sca_util::sca_create_tabular_trace_file("signals");
	sca_util::sca_trace(tfp_tab, AD3, "AD3");
	sca_util::sca_trace(tfp_tab, AD5, "AD5");
	sca_util::sca_trace(tfp_tab, AD7, "AD7");

	//debug
	cout << "Start generating signal.vcd and signal.dat file" << endl;

  sc_start(10, SC_MS);

	sca_util::sca_close_vcd_trace_file(atf);
	sca_util::sca_close_vcd_trace_file(tfp_tab);

	cout << "Finished generating signal.vcd and signal.dat file" << endl;

  return 0;
}
