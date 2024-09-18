#include "inv_subbytes.h"
#include "inv_sbox.h"

void inv_SubBytes(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = applyInvSBox(state[i][j]);
        }
    }
}