#include "subbytes.h"
#include "sbox.h"

void SubBytes(uint8_t state[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] = applySBox(state[i][j]);
        }
    }
}