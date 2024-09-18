#include "addroundkey.h"

void AddRoundKey(uint8_t state[4][4], const uint8_t roundkeys[16]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] ^= roundkeys[4*i + j];
        }
    }
}
