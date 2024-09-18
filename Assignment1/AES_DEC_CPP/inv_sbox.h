#ifndef INV_SBOX_H
#define INV_SBOX_H

#include <cstdint>

extern const uint8_t inv_sbox[16][16];

uint8_t applyInvSBox(uint8_t byte);

#endif // INV_SBOX_H