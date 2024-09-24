#ifndef CRC_CHECK_CONFIG_H_
#define CRC_CHECK_CONFIG_H_

#define NO_CHECK                        0
#define CRC_HARDWARE_CHECK              1
#define CRC_SOFTWARE_CHECK              2
#define CRC_HARDWARE_AND_SOFTWARE_CHECK 3

// <<< Use Configuration Wizard in Context Menu >>>

// <h> CRC Check configuration

// <o CRC_CHECK_TYPE>
// <NO_CHECK=> Hardware check
// <CRC_HARDWARE_CHECK=> Hardware check
// <CRC_SOFTWARE_CHECK=> Software check
// <CRC_HARDWARE_AND_SOFTWARE_CHECK=> Hardware and software check
// <i> Default: CRC_HARDWARE_AND_SOFTWARE_CHECK
#define CRC_CHECK_TYPE              CRC_HARDWARE_AND_SOFTWARE_CHECK
// </h> end led configuration

// <<< end of configuration section >>>

#endif /* CRC_CHECK_CONFIG_H_ */
