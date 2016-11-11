/**
 * @author Alex Stoliar
 * @date 25/09/16
 * @brief Simple Calculation of CRC32 on Array of characters
 */

#include "crc32.h"
#include <stdio.h>
//#define DEBUG

crc32::crc32() {

}

uint32_t crc32::calcCrc(char * buf,int len) {

    uint32_t crc = 0xFFFFFFFFUL; // Max value of unsigned int
    for (int i = 0; i < len; i++) {
        crc = crc32_table[(crc ^ (uint8_t)buf[i]) & 0xFF] ^ (crc >> 8);
    }
#ifdef DEBUG
    crc = crc ^ 0xFFFFFFFFUL;
    printf(" %0x ", (crc >> 24) & 0xFF);
    printf(" %0x ", (crc >> 16) & 0xFF);
    printf(" %0x ", (crc >> 8) & 0xFF);
    printf(" %0x ", crc & 0xFF);
    return crc;
#else
    return crc ^ 0xFFFFFFFFUL;
#endif
}
