#include <rgb_led_intf.h>
#include <pwm_intf.h>

/* Global list of all LEDS */
rgb_led_s leds[MAX_NUM_RGB_LEDS];

/******************************************************************************

  Function: rgb_led_set

******************************************************************************/
/**
  
  @brief set led with specific pulse for red green and blue pins
  @param 
    led_id,
    red_pulse,
    green_pulse,
    blue_pulse

  @return
    uint8_t - 0 success
              1 failed 
     
*/
static uint8_t rgb_led_set
(
 uint8_t led_id,
 uint8_t red_pulse,
 uint8_t green_pulse,
 uint8_t blue_pulse
)
{
  rgb_led_s* led = &leds[led_id];

  led->red_info.config.Pulse = red_pulse;
  pwm_intf_write(&led->red_info.tim_handle,
      &led->red_info.config,
      led->red_info.tim_handle.Channel);

  led->green_info.config.Pulse = green_pulse;
  pwm_intf_write(&led->green_info.tim_handle,
      &led->green_info.config,
      led->green_info.tim_handle.Channel);

  led->blue_info.config.Pulse = blue_pulse;
  pwm_intf_write(&led->blue_info.tim_handle,
      &led->blue_info.config,
      led->blue_info.tim_handle.Channel);
}


/******************************************************************************

  Function: rgb_led_set

******************************************************************************/
/**
  
  @brief set led with specific pulse for red green and blue pins
  @param 
    led_id,
    red_pulse,
    green_pulse,
    blue_pulse

  @return
    uint8_t - 0 success
              1 failed 
     
*/
static uint8_t rgb_led_fill_pwm
(
  TIM_HandleTypeDef     *tim_handle,
  TIM_OC_InitTypeDef     *config
)
{
  /* populate TIM_HandleTypeDef */
  /* populate TIM_OC_InitTypeDef */
}

/******************************************************************************

  Function: rgb_led_set

******************************************************************************/
/**
  
  @brief set led with specific pulse for red green and blue pins
  @param 
    led_id,
    red_pulse,
    green_pulse,
    blue_pulse

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t init_rgb_leds()
{
  memset(leds, 0, sizeof(rgb_led_s)*MAX_NUM_RGB_LEDS);
}

/******************************************************************************

  Function: rgb_led_set

******************************************************************************/
/**
  
  @brief set led with specific pulse for red green and blue pins
  @param 
    led_id,
    red_pulse,
    green_pulse,
    blue_pulse

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t rgb_led_intf_new_init
(
 uint8_t               led_id,
 HAL_TIM_ActiveChannel red_channel,
 HAL_TIM_ActiveChannel green_channel,
 HAL_TIM_ActiveChannel blue_channel,
)
{
  uint8_t ret_val = 1;
  assert(led_id < MAX_NUM_RGB_LEDS);

  rgb_led_s *led = &leds[led_id];

  rgb_led_fill_pwm(
      &led->red_info.tim_handle,
      &led->red_info.config);

  rgb_led_fill_pwm(
      &led->green_info.tim_handle,
      &led->green_info.config);

  rgb_led_fill_pwm(
      &led->blue_info.tim_handle,
      &led->blue_info.config);

  pwm_intf_init(
      &led->red_info.tim_handle,
      &led->red_info.config,
      red_channel);

  pwm_intf_init(
      &led->green_info.tim_handle,
      &led->green_info.config,
      green_channel);

  pwm_intf_init(
      &led->red_info.tim_handle,
      &led->red_info.config,
      red_channel);
}

/******************************************************************************

  Function: rgb_led_set

******************************************************************************/
/**
  
  @brief init the specific led based on id passed in 
  @param 
    led_id,

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t rgb_led_intf_init
(
 uint8_t     led_id
)
{
  uint8_t ret_val = 1;
  assert(led_id < MAX_NUM_RGB_LEDS);
  HAL_TIM_ActiveChannel red_channel;
  HAL_TIM_ActiveChannel green_channel;
  HAL_TIM_ActiveChannel blue_channel;

  /* get channel info */

  rgb_led_intf_new_init(
      led_id,
      red_channel,
      green_channel,
      blue_channel);
}

/******************************************************************************

  Function: rgb_led_set_state

******************************************************************************/
/**
  
  @brief set led with specific pulse for red green and blue pins
  @param 
    led_id,
    state

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t rgb_led_intf_set_state
(
 uint8_t         led_id,
 rgb_led_state_e state
)
{
  uint8_t ret_val = 1;

  if(RGB_LED_MAX <= state)
  {
    leds[led_id].state_mask = state;
    ret_val = 0;
  }

  return ret_val;
}

/******************************************************************************

  Function: rgb_led_intf_set_brightness

******************************************************************************/
/**
  
  @brief set led with specific brightness
  @param 
    led_id,
    brightness

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t rgb_led_intf_set_brightness
(
 uint8_t     led_id,
 uint8_t     brightness
)
{
  uint8_t ret_val = 1;
  uint8_t red_val = 0;
  uint8_t green_val = 0;
  uint8_t blue_val = 0;

  if((brightness < 100) && (brightness > 0))
  {
    ret_val = 0;
    if(leds[led_id].state_mask & RGB_LED_RED)
    {
      red_val = brightness;
    }

    if(leds[led_id].state_mask & RGB_LED_GREEN)
    {
      green_val = brightness;
    }

    if(leds[led_id].state_mask & RGB_LED_BLUE)
    {
      blue_val = brightness;
    }

    rgb_led_set(led_id, red_val, blue_val, green_val);
  }

  return ret_val;
}
