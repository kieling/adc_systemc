#ifndef TLM_COM_H_
#define TLM_COM_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"
#include "systemc.h"
#include <systemc-ams>

//#define DEBUG_PNT

static const double adc_1lsb = 0.305175781e-3;
enum {
	SIZE = 16
};

union real_trans {
	double data_real;
	char data_char[8];
};

real_trans data_ts, data_rs;

struct data_r: sc_module {
	// TLM-2 socket, defaults to 32-bits wide, base protocol
	tlm_utils::simple_target_socket<data_r> socket;
	sc_out<double> parameter_freq;

	SC_CTOR(data_r): socket("socket")
	{
		// Register callback for incoming b_transport interface method call
		socket.register_b_transport(this, &data_r::b_transport);

	}

	// TLM-2 blocking transport method
	virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& delay) {
		tlm::tlm_command cmd = trans.get_command();
		sc_dt::uint64 adr = trans.get_address();
		unsigned char* ptr = trans.get_data_ptr();
		unsigned int len = trans.get_data_length();
		unsigned char* byt = trans.get_byte_enable_ptr();
		unsigned int wid = trans.get_streaming_width();

		if (adr >= sc_dt::uint64(16) || byt != 0 || len > 8 || wid < len)
			SC_REPORT_ERROR("TLM-2",
					"Target does not support given generic payload transaction");

		// Obliged to implement read and write commands
		if (cmd == tlm::TLM_READ_COMMAND)
			memcpy(ptr, &data_rs.data_char, len);
		else if (cmd == tlm::TLM_WRITE_COMMAND)
			memcpy(&data_rs, ptr, len);

		//std::cout << "data in target \n" << std::setprecision(9)
		//		<< data_rs.data_real << endl;

		parameter_freq.write(data_rs.data_real); //pwm_data_rcp[0] * adc_1lsb;

		// Obliged to set response status to indicate successful completion
		trans.set_response_status(tlm::TLM_OK_RESPONSE);
	}

};

struct data_t: sc_module {
	// TLM-2 socket, defaults to 32-bits wide, base protocol
	tlm_utils::simple_initiator_socket<data_t> socket;
	sc_in<bool> clk;

	void thread_process() {
		// TLM-2 generic payload transaction, reused across calls to b_transport

		tlm::tlm_generic_payload *trans = new tlm::tlm_generic_payload;
		sc_time delay = sc_time(0, SC_NS);

		// Generate a random sequence of reads and writes
		for (int i = 0; i < 16; i += 8) {

			tlm::tlm_command cmd = static_cast<tlm::tlm_command>(1);

			// Initialize 8 out of the 10 attributes, byte_enable_length and extensions being unused
			trans->set_command(cmd);
			trans->set_address(i);
			trans->set_data_ptr(
					reinterpret_cast<unsigned char*>(&data_ts.data_char));
			trans->set_data_length(8);
			trans->set_streaming_width(8); // = data_length to indicate no streaming
			trans->set_byte_enable_ptr(0); // 0 indicates unused
			trans->set_dmi_allowed(false); // Mandatory initial value
			trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE); // Mandatory initial value

			socket->b_transport(*trans, delay);  // Blocking transport call

			// Initiator obliged to check response status and delay
			if (trans->is_response_error())
				SC_REPORT_ERROR("TLM-2", "Response error from b_transport");

			//wait(delay);
		}
		//std::cout << "data in initiator \n" << std::setprecision(9)
		//	<< data_ts.data_real << endl;

	}

	SC_CTOR(data_t)
	: socket("socket")  // Construct and name socket
	{
		SC_METHOD (thread_process);
		sensitive << clk.neg();
		dont_initialize();
	}

};

#endif /* TLM_COM_H_ */
