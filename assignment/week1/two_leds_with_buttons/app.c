/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "debug.h"
#include "app_iostream_usart.h"
#include "button_component.h"
#include "em_gpio.h"

void app_init(void)
{
  GPIO_PinModeSet(gpioPortB, 0, gpioModePushPull, 1);
  GPIO_PinModeSet(gpioPortB, 1, gpioModePushPull, 1);
  app_iostream_usart_init();
  simple_button_init();
}

void app_process_action(void)
{
  app_iostream_usart_process_action();
  simple_button_process_action();
}
