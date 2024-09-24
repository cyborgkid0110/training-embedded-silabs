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

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
#include "crc_hardware_check.h"
#include "crc_software_check.h"
#include "app_iostream_usart.h"

//#define FULL_SIZE
#define SHORT_SIZE

#ifdef FULL_SIZE
#define CRC_TEST_FLASH_LENGTH   0x80
#define FLASH_DATA                                                            \
{                                                                             \
    [0 ... 0x0F] 0x12, [0x10 ... 0x1F] 0x34, [0x20 ... 0x2F] 0x56,            \
    [0x30 ... 0x3F] 0x78, [0x40 ... 0x4F] 0x9A, [0x50 ... 0x5F] 0xBC,         \
    [0x60 ... 0x6F] 0xDE, [0x70 ... 0x7F] 0x4F,                               \
};
#else

#ifdef SHORT_SIZE
#define CRC_TEST_FLASH_LENGTH   0x0A
#define FLASH_DATA  {0x47, 0xbc, 0x81, 0x33, 0x34, 0x51, 0xa3, 0x21, 0xb4, 0x19}
#else
#define CRC_TEST_FLASH_LENGTH   0x2
#define FLASH_DATA              {0x09, 0x58}
#endif

#endif

const uint8_t crc_test_flash[CRC_TEST_FLASH_LENGTH] __attribute__((section(".crc_test_section"))) = FLASH_DATA;

void app_init(void)
{
  crc_hardware_check(&crc_test_flash, CRC_TEST_FLASH_LENGTH);
  crc_software_check(&crc_test_flash, CRC_TEST_FLASH_LENGTH);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
}
