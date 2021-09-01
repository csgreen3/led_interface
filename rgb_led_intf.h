#ifndef LED_INTF_H
#define LED_INTF_H

#include <main.h>

#define MAX_NUM_RGB_LEDS 5

typedef enum
{
  RGB_LED_OFF   = 0x0,
  RGB_LED_RED   = 0x1,
  RGB_LED_GREEN = 0x2,
  RGB_LED_BLUE  = 0x4,
  RGB_LED_MAX   = 0x8
} rgb_led_state_e;

typedef struct
{
  TIM_HandleTypeDef    tim_handle;

  TIM_OC_InitTypeDef   config;
}rgb_led_pin_info_s;

typedef struct
{
  uint8_t              id;
  uint8_t              state_mask; 
  rgb_led_pin_info_s   red_info;
  rgb_led_pin_info_s   green_info;
  rgb_led_pin_info_s   blue_info;
}rgb_led_s;

uint8_t init_rgb_leds();

uint8_t rgb_led_intf_new_init
(
 uint8_t     led_id,
 uint8_t     gpio_red,
 uint8_t     gpio_green,
 uint8_t     gpio_blue,
 uint8_t     channel 
);

uint8_t rgb_led_intf_init
(
 uint8_t     led_id
);

uint8_t rgb_led_intf_set_state
(
 uint8_t         led_id,
 rgb_led_state_e state
);

uint8_t rgb_led_intf_set_brightness
(
 uint8_t     led_id,
 uint8_t     brightness
);

#endif
