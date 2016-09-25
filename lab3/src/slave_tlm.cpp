#include "adc.h"

struct Slave_ADC: sc_module
{
  // TLM-2 socket, defaults to 32-bits wide, base protocol
  tlm_utils::simple_target_socket<Slave_ADC> socket;

	// Output values for ADC
	sc_out<int> channel_selector;

  SC_CTOR(Slave_ADC): socket("socket")
  {
    // Register callback for incoming b_transport interface method call
    socket.register_b_transport(this, &Slave_ADC::b_transport);
  }

  // TLM-2 blocking transport method
  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    sc_dt::uint64    adr = trans.get_address();
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned int     len = trans.get_data_length();
    unsigned char*   byt = trans.get_byte_enable_ptr();
    unsigned int     wid = trans.get_streaming_width();

    // Obliged to check address range and check for unsupported features,
    //   i.e. byte enables, streaming, and bursts
    // Can ignore DMI hint and extensions
    // Using the SystemC report handler is an acceptable way of signalling an error

//		cout << "TLM CMD: " << cmd << "  TLM Transaction address: " << adr << endl ;

    if (adr >= sc_dt::uint64(24) || byt != 0 || len > 8 || wid < len)
      SC_REPORT_ERROR("TLM-2", "Target does not support given generic payload transaction");

    // Obliged to implement read and write commands
    if ( cmd == tlm::TLM_READ_COMMAND ){
  		memcpy(ptr, &register_set[adr], len);
		}
    else if ( cmd == tlm::TLM_WRITE_COMMAND ){
			memcpy(&register_set[adr], ptr, len);
		}

		// Write to outut signal the register values
		// value on mux
		channel_selector.write(atoi(&register_set[4][0]));

    // Obliged to set response status to indicate successful completion
    trans.set_response_status( tlm::TLM_OK_RESPONSE );


	//	cout << "Regs : " ;
	//	for (int i =0 ; i<REG_NUMBER; i++)
	//		cout << data[i] << " ";
	//	cout << endl;

  }

};
