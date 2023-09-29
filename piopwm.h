//make with https://wokwi.com/tools/pioasm

// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// --- //
// pwm //
// --- //

#define pwm_wrap_target 0
#define pwm_wrap 6

static const uint16_t pwm_program_instructions[] = {
            //     .wrap_target
    0x9080, //  0: pull   noblock         side 0     
    0xa027, //  1: mov    x, osr                     
    0xa046, //  2: mov    y, isr                     
    0x00a5, //  3: jmp    x != y, 5                  
    0x1806, //  4: jmp    6               side 1     
    0xa042, //  5: nop                               
    0x0083, //  6: jmp    y--, 3                     
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program pwm_program = {
    .instructions = pwm_program_instructions,
    .length = 7,
    .origin = -1,
};

static inline pio_sm_config pwm_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + pwm_wrap_target, offset + pwm_wrap);
    sm_config_set_sideset(&c, 2, true, false);
    return c;
}

static inline void pwm_program_init(PIO pio, uint sm, uint offset, uint pin) {
   pio_gpio_init(pio, pin);
   pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
   pio_sm_config c = pwm_program_get_default_config(offset);
   sm_config_set_sideset_pins(&c, pin);
   pio_sm_init(pio, sm, offset, &c);
}

#endif
