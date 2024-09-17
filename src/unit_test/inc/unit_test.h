/***************************************************************************//**
 * @file
 * @brief
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

#ifndef UNIT_TEST_COMMON_H
#define UNIT_TEST_COMMON_H

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "unity.h"

/*=======Test Runner Used To Run Each Test=====*/
extern void unit_test_run(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num);

#endif  // UNIT_TEST_COMMON_H