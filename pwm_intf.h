#ifndef PWM_INTF_H
#define PWM_INTF_H

#include <main.h>

uint8_t pwm_intf_init
(
  TIM_HandleTypeDef     *tim_handle,
  TIM_OC_InitTypeDef     *config,
  HAL_TIM_ActiveChannel  channel
);

uint8_t pwm_intf_write
(
  TIM_HandleTypeDef     *tim_handle,
  TIM_OC_InitTypeDef     *config,
  HAL_TIM_ActiveChannel  channel
);

#endif
