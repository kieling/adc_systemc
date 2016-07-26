//
//  test_bench
//  (c) TU Kaiserslautern,
//  AG Design of Cyber-Physical Systems
//  Contains template class for modeling of an programmable gain amplifier and offset module

#include "modules.h"
#include "stimuli.h"


int sc_main(int argc, char* argv[])
{
  
    sca_tdf::sca_signal<int> sig1;
    sca_tdf::sca_signal<int> sig2;
    sca_tdf::sca_signal<int> sig3;
    
    stimuli stim("stim",5);
    stim.out(sig1);
    
    amp<int> ampl("ampl",10); // instance the amplifer
    ampl.in(sig1);
    ampl.out(sig2);
    
    add_offset<int> offset("offset",4);// instance the offset
    offset.in(sig1);
    offset.out(sig3);
 
    // open trace files in tabular format
    sca_util::sca_trace_file* atf = sca_util::sca_create_tabular_trace_file("amp.dat");
	sca_util::sca_trace(atf, sig2, "amplified signal");
    
    sca_util::sca_trace_file* otf = sca_util::sca_create_tabular_trace_file("offset.dat");
	sca_util::sca_trace(otf, sig3, "offset signal");
	

    sc_start(1, SC_US);
    
    // close the trace files
    sca_util::sca_close_vcd_trace_file(atf);
    sca_util::sca_close_vcd_trace_file(otf);
    
    return 0;
    
}
