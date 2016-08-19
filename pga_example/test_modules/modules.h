//
//  modules.h
//
//  (c) TU Kaiserslautern,
//  AG Design of Cyber-Physical Systems
//  Contains template class for modeling of an programmable gain amplifier and offset module


#ifndef _MODULES_H
#define _MODULES_H

#include <systemc-ams.h>

using namespace std;

// Generic amplifier class
template <class T>
class amp: public sca_tdf::sca_module
{
    public:
        sca_tdf::sca_in<T> in;               // input port
        sca_tdf::sca_out<T> out;             // output port

    private:
        T result, gain;


    void processing();

    public:
        // The constructor of the module.
        amp(sc_core::sc_module_name n, T _gain=1)
        {
            gain=_gain;
        }
};


template <class T>
void amp<T>::processing()
{
  result=gain*in.read();
  out.write(result);

}

// Generic class for adding offset

template <class T>
class add_offset: public sca_tdf::sca_module
{
public:
    sca_tdf::sca_in<T> in;               // input port
    sca_tdf::sca_out<T> out;             // output port

private:
    T result, offset;


    void processing();

public:
    // The constructor of the module.
    add_offset(sc_core::sc_module_name n, T _offset=0)
    {
        offset=_offset;
    }
};

template <class T>
void add_offset<T>::processing()
{
    result=in.read()+offset;
    out.write(result);

}


#endif
