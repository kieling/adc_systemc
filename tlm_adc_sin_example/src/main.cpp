//-------------------------------------------------------------------------------------------
// Copyright (c) 2014, Design of Cyber-Physical-Systems, TU Kaiserslautern
// Authors:
// Thiyagarajan Purusothaman
// Contact:
//   thiyag@cs.uni-kl.de
//-------------------------------------------------------------------------------------------
//

#include <systemc-ams.h>
#include <tuv_ams_library.h>
#include <tlm_com.h>
#include <ref_src.h>

#include <conv_tdf_sc.h>

using namespace TUV_ams_lib::bb;

SCA_TDF_MODULE(drain) {
	sca_tdf::sca_in<sc_bv<16> > in;SCA_CTOR(drain) {
	}
};

int sc_main(int argc, char* argv[]) {

	sc_set_time_resolution(10, SC_NS);	// setting the time resolution
	sca_tdf::sca_signal<double> dummy;
	sca_tdf::sca_signal<double> freq_val_tdf;
	sc_core::sc_signal<double> freq_val_de;
	sca_tdf::sca_signal<double> amp_val;

	/*parameter generator for sine wave*/
	parameters ref_src1("ref_src1");
	ref_src1.out(dummy);

	sc_clock clk1("clk1", 100, SC_NS);

	/*TLM initiator and target*/
	data_t *parameter_initiator= new data_t("data_t");
	parameter_initiator->clk(clk1);

	data_r *parameter_target= new data_r("data_r");
	parameter_target->parameter_freq(freq_val_de);

	parameter_initiator->socket.bind(parameter_target->socket);

	/*conversion between Discrete Event (DE) and AMS Timed Data Flow (TDF) MoC*/
	conv_sc_tdf_real de2tdf("de2tdf");
	de2tdf.inDE(freq_val_de);
	de2tdf.outTDF(freq_val_tdf);


	/* ***** Defining signals and parameters ***** */

	sca_tdf::sca_signal<double> sig_sin_out;
	sca_tdf::sca_signal<sc_bv<16> > sig_adc_out;

	sine Sine("Sine", 0, 2, 0.0, 0.0, false, true, 1); // (amp_c and freq_c are false)
	Sine.set_timestep(10, sc_core::SC_US); // Time step (sampling rate) of port "out" = 10 us
	Sine.freq_con(&freq_val_tdf);// need this as port to vary the frequency through tlm interface
	Sine.out(sig_sin_out);
	Sine.set_timestep(100, sc_core::SC_NS);

    // A simple Analog to Digital conversion
	adc<16> i_adc("adc", 2, 0.0, 0.0);  //use default parameters
	i_adc.in(sig_sin_out);
	i_adc.out(sig_adc_out);

	// This is only a module used to consume tokens as we can not let a
	// systemc-ams scheduling loop open.
	drain drn("drn");
	drn.in(sig_adc_out);

	/* ***** tracning signals VCD and Tabular format***** 
     With GTKwave tool using dataformat and analog extension settings the 
     analog signals can be viewed together with digital signals.
     For tabular format the gaw tool can be used to view analog signals
     http://gaw.tuxfamily.org/linux/gaw.php
     */
	sca_util::sca_trace_file* atf = sca_util::sca_create_vcd_trace_file("tr");
	sca_util::sca_trace(atf, sig_sin_out, "sig_sin_out");
	sca_util::sca_trace(atf, sig_adc_out, "sig_adc_out");
	sca_util::sca_trace(atf, freq_val_de, "freq_val_de");


	sca_util::sca_trace_file* tfp_tab = sca_util::sca_create_tabular_trace_file(
			"signals");
	sca_util::sca_trace(tfp_tab, sig_sin_out, "sig_sin_out");
	sca_util::sca_trace(tfp_tab, sig_adc_out, "sig_adc_out");
	sca_util::sca_trace(tfp_tab, freq_val_de, "freq_val_de");


	//debug
	cout << "Start generating signal.vcd and signal.dat file" << endl;

	//simulation start
	sc_start(1, SC_MS);

	//close tracing file
	sca_util::sca_close_vcd_trace_file(atf);
	sca_util::sca_close_vcd_trace_file(tfp_tab);

	cout << "Finished generating signal.vcd and signal.dat file" << endl;

	return 0;
}

