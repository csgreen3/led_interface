#ifndef PWM_INTF_H
#define PWM_INTF_H

#include <main.h>

/******************************************************************************

  Function: pwm_intf_init

******************************************************************************/
/**
  
  @brief init PWM pulse to speceific channel
  @param 
    tim_handle 
    config
    channel

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t pwm_intf_init
(
  TIM_HandleTypeDef      *tim_handle,
  TIM_OC_InitTypeDef     *config,
  HAL_TIM_ActiveChannel  channel
);

/******************************************************************************

  Function: pwm_intf_write 

******************************************************************************/
/**
  
  @brief write PWM pulse to speceific channel
  @param 
    tim_handle 
    config
    channel

  @return
    uint8_t - 0 success
              1 failed 
     
*/
uint8_t pwm_intf_write
(
  TIM_HandleTypeDef     *tim_handle,
  TIM_OC_InitTypeDef     *config,
  HAL_TIM_ActiveChannel  channel
);

#endif
