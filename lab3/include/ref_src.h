/*
 * ref_src.h
 *
 *  Created on: Dec 13, 2013
 *      Author: thiag
 */

#ifndef REF_SRC_H
#define REF_SRC_H

#include <systemc-ams>

SCA_TDF_MODULE(parameters)
{
	sca_tdf::sca_out<double> out;
	const sca_time t_step = sca_core::sca_time(100, sc_core::SC_NS);

	parameters(sc_core::sc_module_name nm):out("out") {

	}

	void set_attributes() {
		out.set_timestep(t_step);
		accept_attribute_changes();
	}

	void processing() {

		double t = this->get_time().to_seconds();
		//std::cout << "t is \n" << t <<endl;
		out.write(data_ts.data_real);
		if (t <= 0.0001) {
			data_ts.data_real = 111111.1;

		}

		if (t >= 0.0001 && t <= 0.0002) {
			data_ts.data_real = 11111111.1;

		}

		if (t >= 0.0002 && t <= 0.0003) {
			data_ts.data_real = 11111.1;

		}
		if (t >= 0.0003 && t <= 0.0004) {
			data_ts.data_real = 10000.1;

		}

		if (t >= 0.0005 && t <= 0.0007) {
			data_ts.data_real = 100000.1;

		}

	}

};

#endif /* REF_SRC_H_ */
