// Shows the generic payload, sockets, and blocking transport interface.
// Shows the responsibilities of initiator and target with respect to the generic payload.
// Has only dummy implementations of the direct memory and debug transaction interfaces.
// Does not show the non-blocking transport interface.
#ifndef ADC_H_
#define ADC_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES

// System C
#include <systemc.h>
#include <systemc-ams.h>

// Aux
#include "tuv_ams_library.h"
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

// number of registers
#define REG_NUMBER 24

#define ADC_BASE_ADDR 0x40038000

#define ADC_CR 		0x00
#define ADC_MR 		0x04
#define ADC_CHER 	0x10
#define ADC_CHDR 	0x14
#define ADC_CHSR 	0x18
#define ADC_CGR 	0x48
#define ADC_COR 	0x4C
#define ADC_CDR0 	0x50
#define ADC_CDR1 	0x54
#define ADC_CDR2 	0x58
#define ADC_CDR3 	0x5C
#define ADC_CDR4 	0x60
#define ADC_CDR5 	0x64
#define ADC_CDR6 	0x68
#define ADC_CDR7 	0x6C
#define ADC_CDR8 	0x70
#define ADC_CDR9 	0x74
#define ADC_CDR10	0x78
#define ADC_CDR11	0x7C
#define ADC_CDR12	0x80
#define ADC_CDR13	0x84
#define ADC_CDR14	0x88
#define ADC_CDR15 0x8C
#define ADC_WPMR 	0xE4


// Set of register on slave
char register_set[REG_NUMBER][8];

#endif
