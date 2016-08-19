
// Shows the generic payload, sockets, and blocking transport interface.
// Shows the responsibilities of initiator and target with respect to the generic payload.
// Has only dummy implementations of the direct memory and debug transaction interfaces.
// Does not show the non-blocking transport interface.
#ifndef ADC_H_
#define ADC_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES

// System C
#include "systemc"
#include <systemc-ams.h>

// Aux
#include <tuv_ams_library.h>
#include <tlm_com.h>
#include <ref_src.h>
#include <conv_tdf_sc.h>

// TLM headers
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"

// AMS headers
#include "modules.h"
#include "stimuli.h"

using namespace sc_core;
using namespace sc_dt;
using namespace std;
using namespace TUV_ams_lib::bb;

#define ADC_BASE_ADDR 0x40038000
#define ADC_CR 0x00
#define ADC_MR 0x04
#define ADC_CHER 0x10
#define ADC_CHDR 0x14
#define ADC_CHSR 0x18
#define ADC_CGR 0x48
#define ADC_COR 0x4C
#define ADC_CDR0 0x50
#define ADC_CDR15 0x8C
#define ADC_WPMR 0xE4

#endif
