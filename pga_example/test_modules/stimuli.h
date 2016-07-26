//
//  modules.h
//
//  (c) TU Kaiserslautern,
//  AG Design of Cyber-Physical Systems
//  Contains template class for modeling of an programmable gain amplifier and offset module


#ifndef _INPUT_H
#define _INPUT_H


#include <systemc-ams.h>


SCA_TDF_MODULE(stimuli)
{
  public:
    sca_tdf::sca_out<int> out;
    
  private:
    
    int val;
    sca_core::sca_time t_step;
    
    void set_attributes()
    {
        set_timestep(t_step);
    }
    
    void processing()
    {
        out.write(val);
    }
    
  public:
    
    stimuli(sc_core::sc_module_name n,int _val, sca_core::sca_time t_step_ = sca_core::sca_time(0.1, sc_core::SC_US)):t_step(t_step_), val(_val){}
    
};


#endif

