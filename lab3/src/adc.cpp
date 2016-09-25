#include "adc.h"

SCA_TDF_MODULE(ADC)
{
	sca_tdf::sca_out<double> out;

	sca_tdf::sca_in<double> vin;

	double ampl;   // output amplitude (v)
	double freq;   // centre frequency (Hz)
	double kvco;   // (Hz/V)

	vco ( sc_core::sc_module_name m, double ampl_ = 1.0, double freq_ = 1.0e9, double kvco_ = 1.0)  :
		ampl(ampl_), freq(freq_), kvco(kvco_) {}

	void set_attributes(){}

	void processing()
	{
		double ts;
		ts = get_timestep().to_seconds();
		out = ampl*sin(2.0*M_PI*(freq+(kvco*vin.read()))*ts);
	}

};
