#include "gpio_alias.h"
#include "gpio.h"
#include "exti.h"
#include <string.h>

const GPIO GPIO_TABLE[] = {
    /* Application PWM*/
    /* RGB_LED 1 ADC */
    FILL_GPIO("LED_1_RED",    GPIOA,  0, OUTPUT, LOW_SPEED, NONE, true, BRAKE)
    FILL_GPIO("LED_1_GREEN",    GPIOB,  10, OUTPUT, LOW_SPEED, NONE, true, PROP)
    FILL_GPIO("LED_1_BLUE",    GPIOB,  11, OUTPUT, LOW_SPEED, NONE, true, BRAKE) 

    /* RGB_LED_2  ADC */
    FILL_GPIO("LED_1_RED",    GPIOA,  0, OUTPUT, LOW_SPEED, NONE, true, BRAKE)
    FILL_GPIO("LED_1_GREEN",    GPIOB,  10, OUTPUT, LOW_SPEED, NONE, true, PROP)
    FILL_GPIO("LED_1_BLUE",    GPIOB,  11, OUTPUT, LOW_SPEED, NONE, true, BRAKE) 

};

const uint8_t NUM_GPIO_ALIAS = sizeof(GPIO_TABLE)/sizeof(GPIO);

int gpioAliasInit(){
  int i;
  GPIO_TypeDef * port;
  uint8_t pin;

  for(i = 0; i < NUM_GPIO_ALIAS; i++){
    if (GPIO_TABLE[i].usable){
      port = GPIO_TABLE[i].port;
      pin = GPIO_TABLE[i].pin;

      gpio_setClock(port, true);
      gpio_setMode(port, pin, GPIO_TABLE[i].mode);
      gpio_setSpeed(port, pin, GPIO_TABLE[i].speed);

      if (GPIO_TABLE[i].mode == ALT)
        gpio_setAlternateFunc(port, pin, GPIO_TABLE[i].af_val);

      if (GPIO_TABLE[i].group == I2C)
        gpio_openDrainState(port, pin, true);

      if (GPIO_TABLE[i].group == RETRO)
        exti_config(port, pin, true, false, true);

      if (GPIO_TABLE[i].mode == OUTPUT)
        gpio_writePin(port, pin, 0);
    }
  }
  return 0;
}

