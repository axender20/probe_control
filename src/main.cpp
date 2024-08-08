#include "Arduino.h"
#include "DEBUG.h"

/*
  ! Todos los CMDs entre la pantalla y controlador deben terminar con el ascci'003'
  * 
*/  

const char _CMD_EC_ = char(3);

#define main_port Serial2
const uint8_t port_rxd = 21;
const uint8_t port_txd = 20;
const uint8_t port_gpr = 19;
const uint8_t port_time_out = 100;
size_t port_fifo_size = 256;
unsigned long port_baud_rate = 115200;

void init_main_port();

void setup() {
  init_debug();
  init_main_port();
}

void loop() {
  if (main_port.available() > 0) {
    char x = main_port.read();
    object_serial_pio.write(x);
  }
}

void init_main_port() {
  main_port.setPinout(port_txd, port_rxd);
  main_port.setTimeout(port_time_out);
  main_port.setFIFOSize(port_fifo_size);
  main_port.begin(port_baud_rate);
}
