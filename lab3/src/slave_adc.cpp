#include "adc.h"


struct Slave_ADC: sc_module
{
  // TLM-2 socket, defaults to 32-bits wide, base protocol
  tlm_utils::simple_target_socket<Slave_ADC> socket;

  enum { SIZE = 256 };

	// 256 - 32 bit values
  int mem[SIZE];

  SC_CTOR(Slave_ADC): socket("socket")
  {
    // Register callback for incoming b_transport interface method call
    socket.register_b_transport(this, &Slave_ADC::b_transport);

    // Initialize memory
    for (int i = 0; i < SIZE; i++)
      mem[i] = 0x00000000;
  }

  // TLM-2 blocking transport method
  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    sc_dt::uint64    adr = trans.get_address() / 4;
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned int     len = trans.get_data_length();
    unsigned char*   byt = trans.get_byte_enable_ptr();
    unsigned int     wid = trans.get_streaming_width();

    // Obliged to check address range and check for unsupported features,
    //   i.e. byte enables, streaming, and bursts
    // Can ignore DMI hint and extensions
    // Using the SystemC report handler is an acceptable way of signalling an error

    if (adr >= sc_dt::uint64(SIZE) || byt != 0 || len > 4 || wid < len)
      SC_REPORT_ERROR("TLM-2", "Target does not support given generic payload transaction");

    // Obliged to implement read and write commands
    if ( cmd == tlm::TLM_READ_COMMAND )
      memcpy(ptr, &mem[adr], len);
    else if ( cmd == tlm::TLM_WRITE_COMMAND )
      memcpy(&mem[adr], ptr, len);

    // Obliged to set response status to indicate successful completion
    trans.set_response_status( tlm::TLM_OK_RESPONSE );
  }


	// ADC instantiation

	//auxiliar
	sca_tdf::sca_signal<int> offset_to_pga;
	sca_tdf::sca_signal<int> pga_to_adc;
	sca_tdf::sca_signal<int> adc_to_reg;

	sca_tdf::sca_signal<sc_bv<16> > sig_adc_out;

	// Inputs
	sca_tdf::sca_signal<double> AD3;
	sca_tdf::sca_signal<double> AD5;
	sca_tdf::sca_signal<double> AD7;
	sca_tdf::sca_signal<int> ADTRG;
	sca_tdf::sca_signal<int> GND;


	// Sin
	// sine Sine("Sine", 0, 2, 0.0, 0.0, false, true, 1); // (amp_c and freq_c are false)
	// Sine.set_timestep(10, sc_core::SC_US); // Time step (sampling rate) of port "out" = 10 us
	// Sine.freq_con(&freq_val_tdf); // need this as port to vary the frequency through tlm interface
	// Sine.out(AD3);
	// Sine.set_timestep(100, sc_core::SC_NS);
	//
	// // Cos -- sin phase shifted
	// sine Cos("Cos", 0, 2.5, 3.14, 0.0, false, true, 1); // (amp_c and freq_c are false)
	// Cos.set_timestep(10, sc_core::SC_US); // Time step (sampling rate) of port "out" = 10 us
	// Cos.freq_con(&freq_val_tdf); // need this as port to vary the frequency through tlm interface
	// Cos.out(AD5);
	// Cos.set_timestep(100, sc_core::SC_NS);
	//
	// // Saw tooth
 // 	// saw_gen(sc_core::sc_module_name n, double freq,double _amp, double _ofs=0.0, int d_rate=1);
	// saw_gen Saw("Saw", 0, 2.5, 0.0, 1); // (amp_c and freq_c are false)
	// Saw.out(AD7);
	//
	// // OFFSET
	// add_offset<int> offset("offset",4);// instance the offset
	// offset.in(sig1);
	// offset.out(offset_to_pga);
	//
	// // PGA
	// amp<int> ampl("ampl",10); // instance the amplifer
	// ampl.in(offset_to_pga);
	// ampl.out(pga_to_adc);
	//
	// // 12 bit adc converter
	// //	adc(sc_core::sc_module_name n, double uref=1.0, double gain_e=0.0, double offset_e=0.0, int nl_m=0)
	// adc<12> i_adc("adc", 2, 0.0, 0.0);  //use default parameters
	// i_adc.in(pga_to_adc);
	// i_adc.out(adc_to_reg);





};
