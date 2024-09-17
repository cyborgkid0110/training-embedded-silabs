/***************************************************************************/ /**
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

/***************************************************************************/ /**
 * Initialize application.
 ******************************************************************************/
#include <stdio.h>
#include "dynamic_allocate_function.h"
#include "unit_test.h"

void testDynamAlloc(void) 
{
  uint16_t *ptr = NULL;
  dynamAlloc(&ptr);
  TEST_ASSERT_NOT_EQUAL(NULL, ptr);
}

void app_init(void) 
{
    printf("==== UNIT TEST PROGRAM ====\n");
    printf("==== UNIT TEST BEGIN ====\n");
    unit_test_run(testDynamAlloc,"testDynamAlloc",25);
    printf("\n==== UNIT TEST END ====\n");
}

/***************************************************************************/ /**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void) {}
