#pragma once

#ifndef _DEBUG_H_
#define _DEBUG_H_


#define DEBUG_ENABLE

#include "pico/stdlib.h"

/// @brief Configuracion para el DEBUG SERIAL
const uint8_t debug_pin_tx = 17;
const uint8_t debug_pin_rx = 16;

#ifndef DEBUG_ENABLE
#define DEBUG_PRINTLN(_var)
#define DEBUG_INIT(_baud)
#endif

#ifdef DEBUG_ENABLE
#include "SerialPIO.h"
extern SerialPIO object_serial_pio;
#define SERIAL_DEBUG object_serial_pio
#define DEBUG_PRINTLN(_var) (SERIAL_DEBUG.println(_var))
#define DEBUG_INIT(_baud)(SERIAL_DEBUG.begin(_baud)) 
#endif

void init_debug();

#endif