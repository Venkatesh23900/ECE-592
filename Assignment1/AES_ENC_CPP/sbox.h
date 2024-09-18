#ifndef SBOX_H
#define SBOX_H

#include <cstdint>

extern const uint8_t sbox[16][16];

uint8_t applySBox(uint8_t byte);

#endif // SBOX_H
