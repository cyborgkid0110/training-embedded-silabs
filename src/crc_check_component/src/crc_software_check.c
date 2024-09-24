#include <stdio.h>
#include <stdint.h>
#include "crc_check_config.h"

#define CRC_TEST_FLASH_LENGTH   0x80
#define POLYNOMIAL              0x1021
#define INITIAL_VALUE           0xFFFF

void crc_software_check(const uint8_t *data, size_t length) {

#if (CRC_CHECK_TYPE == CRC_SOFTWARE_CHECK ||                            \
CRC_CHECK_TYPE == CRC_HARDWARE_AND_SOFTWARE_CHECK)
  uint16_t crc = INITIAL_VALUE;
  for (size_t i = 0; i < length; i++) {
    crc ^= (data[i] << 8);
    for (int j = 0; j < 8; j++) {
      if (crc & 0x8000) {
        crc = (crc << 1) ^ POLYNOMIAL;
      } else {
        crc = crc << 1;
      }
    }
  }
  printf("CRC software check: 0x%x\n", crc);
#endif

}


