#include "em_gpcrc.h"
#include "crc_check_config.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define CRC16_CCITT_POLY        0x1021
#define CRC_INITIAL_VALUE       0xFFFF

void crc_hardware_check(const uint8_t* data, size_t length) {
#if (CRC_CHECK_TYPE == CRC_HARDWARE_CHECK                                 \
|| CRC_CHECK_TYPE == CRC_HARDWARE_AND_SOFTWARE_CHECK)
  GPCRC_Init_TypeDef init = GPCRC_INIT_DEFAULT;
  init.crcPoly = CRC16_CCITT_POLY;
  init.initValue = CRC_INITIAL_VALUE;
  init.reverseBits = true;
  GPCRC_Init(GPCRC, &init);

  GPCRC_Start(GPCRC);
  for (size_t i = 0; i < length; i++) {
//    printf("Input byte: 0x%x\n", data[i]);
    GPCRC_InputU8(GPCRC, (uint8_t) data[i]);
  }

  uint16_t checksum = (uint16_t)GPCRC_DataReadBitReversed(GPCRC);
  printf("\nAddress start: %p\n", data);
  printf("CRC hardware check: ");
  printf("0x%x\n", checksum);
#endif
}

