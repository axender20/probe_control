#include "DEBUG.h"


#ifdef DEBUG_ENABLE
SerialPIO object_serial_pio(debug_pin_tx, debug_pin_rx);
#endif

void init_debug() {
  DEBUG_INIT(115200);
  DEBUG_PRINTLN("_Init code_");
}
