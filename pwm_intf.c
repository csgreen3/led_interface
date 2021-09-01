#include <pwm_intf.h>

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
  TIM_HandleTypeDef     *tim_handle,
  TIM_OC_InitTypeDef     *config,
  HAL_TIM_ActiveChannel  channel
)
{
  uint8_t ret_val = 0;

  do
  {
    if(HAL_TIM_PWM_Init(tim_handle) != HAL_OK)
    {
      ret_val = 0;
      break;
    }

    if(HAL_TIM_PWM_ConfigChannel(tim_handle, config, channel) != HAL_OK)
    {
      ret_val = 0;
      break;
    }

    if(HAL_TIM_PWM_Start(tim_handle, channel) != HAL_OK)
    {
      ret_val = 0;
      break;
    }
  } while(1);

  return ret_val;
}

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
  TIM_HandleTypeDef      *tim_handle,
  TIM_OC_InitTypeDef     *config,
  HAL_TIM_ActiveChannel  channel
)
{
  uint8_t ret_val = 0;

  do
  {
    if (HAL_TIM_PWM_ConfigChannel(tim_handle, config, channel) != HAL_OK)
    {
      ret_val = 1;
      break;
    }

    if (HAL_TIM_PWM_Start(tim_handle, channel) != HAL_OK)
    {
      ret_val = 1;
      break;
    }
  } while(1);
  return ret_val;
}
