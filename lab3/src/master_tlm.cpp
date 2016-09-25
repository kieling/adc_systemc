#include "adc.h"

// Initiator module generating generic payload transactions
struct Master_ADC: sc_module
{
  // TLM-2 socket, defaults to 32-bits wide, base protocol
  tlm_utils::simple_initiator_socket<Master_ADC> socket;

  // Internal data buffer used by initiator with generic payload
	char data_to_send[8];

  SC_CTOR(Master_ADC): socket("socket")  // Construct and name socket
  {
  //  SC_THREAD(thread_process);
  }

	// Configure ADC (all registers), Prog Gain Amplifier (PGA), Sampling Time and Channel
	void ADC_Configuration(int address, char *value){
		tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
		sc_time delay = sc_time(10, SC_NS);

		char data_t[8];

		strncpy(data_t,value,8);

		int i;
		int aux;

		cout << "Call to ADC_Configuration -- addr: " << address << " value: " << value << endl;

		aux = address - ADC_BASE_ADDR;
		switch (aux){
			case ADC_CR: 				i = 0; break;
			case ADC_MR: 				i = 1; break;
			case ADC_CHER: 			i = 2; break;
			case ADC_CHDR: 			i = 3; break;
		//	case ADC_CHSR: 			i = 4; break; // Read only
			case ADC_CGR: 			i = 5; break;
			case ADC_COR: 			i = 6; break;
			case ADC_CDR0: 			i = 7; break;
			case ADC_CDR1: 			i = 8; break;
			case ADC_CDR2: 			i = 9; break;
			case ADC_CDR3: 			i = 10; break;
			case ADC_CDR4: 			i = 11; break;
			case ADC_CDR5: 			i = 12; break;
			case ADC_CDR6: 			i = 13; break;
			case ADC_CDR7: 			i = 14; break;
			case ADC_CDR8: 			i = 15; break;
			case ADC_CDR9: 			i = 16; break;
			case ADC_CDR10: 		i = 17; break;
			case ADC_CDR11: 		i = 18; break;
			case ADC_CDR12: 		i = 19; break;
			case ADC_CDR13: 		i = 20; break;
			case ADC_CDR14: 		i = 21; break;
			case ADC_CDR15: 		i = 22; break;
			case ADC_WPMR: 			i = 23; break;
		}

		// Initialize 8 out of the 10 attributes, byte_enable_length and extensions being unused
		trans->set_command( tlm::TLM_WRITE_COMMAND );
		trans->set_address( i );
		trans->set_data_ptr( reinterpret_cast<unsigned char*>(&data_t) );
		trans->set_data_length( 8 );
		trans->set_streaming_width( 8 ); // = data_length to indicate no streaming
		trans->set_byte_enable_ptr( 0 ); // 0 indicates unused
		trans->set_dmi_allowed( false ); // Mandatory initial value
		trans->set_response_status( tlm::TLM_INCOMPLETE_RESPONSE ); // Mandatory initial value

		socket->b_transport( *trans, delay );  // Blocking transport call

		// Initiator obliged to check response status and delay
		if ( trans->is_response_error() )
			SC_REPORT_ERROR("TLM-2", "Response error from b_transport");

		cout << "trans = { " << 'W' << ", " << i
				 << " } , data = " << hex << data_t << " at time " << sc_time_stamp()
				 << " delay = " << delay << endl;

		// Realize the delay annotated onto the transport call
		//wait(delay);

		cout << endl;
	}

	// Return current configuration
	void ADC_GetStatus(){
		// TLM-2 generic payload transaction, reused across calls to b_transport
		tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
		sc_time delay = sc_time(10, SC_NS);

		char data[8];

		cout << "Call to ADC_GetStatus" << endl;

		// Read all registers
		for (int i = 0; i < REG_NUMBER; i++)
		{
			tlm::tlm_command cmd = tlm::TLM_READ_COMMAND;

			// Initialize 8 out of the 10 attributes, byte_enable_length and extensions being unused
			trans->set_command( cmd );
			trans->set_address( i );
			trans->set_data_ptr( reinterpret_cast<unsigned char*>(&data) );
			trans->set_data_length( 8 );
			trans->set_streaming_width( 8 ); // = data_length to indicate no streaming
			trans->set_byte_enable_ptr( 0 ); // 0 indicates unused
			trans->set_dmi_allowed( false ); // Mandatory initial value
			trans->set_response_status( tlm::TLM_INCOMPLETE_RESPONSE ); // Mandatory initial value

			socket->b_transport( *trans, delay );  // Blocking transport call

			// Initiator obliged to check response status and delay
			if ( trans->is_response_error() )
				SC_REPORT_ERROR("TLM-2", "Response error from b_transport");

			cout << "trans = { " << (cmd ? 'W' : 'R') << ", " << hex << i
					 << " } , data = " << hex << data << " at time " << sc_time_stamp()
					 << " delay = " << delay << endl;

			// Realize the delay annotated onto the transport call
	//		wait(delay);
		}

		cout << endl;
	}

	// return the sampled data from ADC data register for a channel
	void ADC_GetData(int channel){
		// TLM-2 generic payload transaction, reused across calls to b_transport
		tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
		sc_time delay = sc_time(10, SC_NS);

		cout << "Call to ADC_GetData -- channel: " << channel << endl;

		char data[8];

		int address;
		address = channel + 7;

		// Initialize 8 out of the 10 attributes, byte_enable_length and extensions being unused
		trans->set_command( tlm::TLM_READ_COMMAND );
		trans->set_address( address );
		trans->set_data_ptr( reinterpret_cast<unsigned char*>(&data) );
		trans->set_data_length( 8 );
		trans->set_streaming_width( 8 ); // = data_length to indicate no streaming
		trans->set_byte_enable_ptr( 0 ); // 0 indicates unused
		trans->set_dmi_allowed( false ); // Mandatory initial value
		trans->set_response_status( tlm::TLM_INCOMPLETE_RESPONSE ); // Mandatory initial value

		socket->b_transport( *trans, delay );  // Blocking transport call

		// Initiator obliged to check response status and delay
		if ( trans->is_response_error() )
			SC_REPORT_ERROR("TLM-2", "Response error from b_transport");

		cout << "trans = { " << 'R' << ", " << hex << address
				 << " } , data = " << hex << data << " at time " << sc_time_stamp()
				 << " delay = " << delay << endl;

		// Realize the delay annotated onto the transport call
		//		wait(delay);

		cout << endl;
	}

};
