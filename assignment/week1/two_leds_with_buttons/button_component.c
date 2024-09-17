#include "sl_simple_button_instances.h"
#include "button_component.h"
#include "em_gpio.h"
#include "sl_udelay.h"
#include "debug.h"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

#ifndef BUTTON_INSTANCE_0
#define BUTTON_INSTANCE_0   sl_button_button0
#endif

#ifndef BUTTON_INSTANCE_1
#define BUTTON_INSTANCE_1   sl_button_button1
#endif

/* Configure debug mode */

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/
uint8_t state = 1;

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************//**
 * This function is only used for knowing that button is initialized.
 * The function to initialize button is in "sl_simple_button_instances.h"
 ******************************************************************************/
void simple_button_init(void)
{
  return;
}

/***************************************************************************//**
 * Ticking function.
 ******************************************************************************/
void simple_button_process_action(void)
{
  if (state) {
      GPIO_PinOutSet(gpioPortB, 1);
  }
  else {
      GPIO_PinOutToggle(gpioPortB, 1);
      sl_udelay_wait(500000);
  }
  return;
}

/***************************************************************************//**
 * Callback on button change.
 ******************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{

  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {
      if (handle == &BUTTON_INSTANCE_0) {
          //#if(DEBUG_MODE)
          PRINT_LOG("BTN0 Pressed\n");
          //#endif
          GPIO_PinOutToggle(gpioPortB, 0);
      }
      if (handle == &BUTTON_INSTANCE_1) {
          #if(DEBUG_MODE)
          PRINT_MULTI_ARG("[TLG] Successful with return code: %d", 132);
          #endif
          state = !state;
      }
  }
}
