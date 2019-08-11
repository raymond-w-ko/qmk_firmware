#pragma once

// needed for process_console_data_user()
// #define CONSOLE_IN_ENABLE

// Use I2C or Serial, not both
// #define USE_SERIAL
#define USE_I2C

// Select hand configuration
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 0
#undef DEBOUNCE
#define DEBOUNCE 5

// RGB
#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

//#define STRICT_LAYER_RELEASE
