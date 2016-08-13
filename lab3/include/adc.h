

// Shows the generic payload, sockets, and blocking transport interface.
// Shows the responsibilities of initiator and target with respect to the generic payload.
// Has only dummy implementations of the direct memory and debug transaction interfaces.
// Does not show the non-blocking transport interface.
#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"

#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;
