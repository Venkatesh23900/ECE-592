#include "mixcolumns.h"

/* multiplication by 2 in galios field is essentially shifting one bit to the left, if the original byte had '1' at the MSB,
    then shift it by one bit to the left and xor the result with {8'h1b} */

uint8_t mul2(uint8_t x) {
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}

/* multiplication by 3 in galios field is done by perfroming xor on the result of multiplication by 2 with the original input byte */

uint8_t mul3(uint8_t x) {
    return mul2(x) ^ x;
}


void MixColumns(uint8_t state[4][4]) {
    for (int i = 0; i < 4; ++i) {
        uint8_t a0 = state[i][0];
        uint8_t a1 = state[i][1];
        uint8_t a2 = state[i][2];
        uint8_t a3 = state[i][3];

        state[i][0] = mul2(a0) ^ mul3(a1) ^ a2 ^ a3;
        state[i][1] = a0 ^ mul2(a1) ^ mul3(a2) ^ a3;
        state[i][2] = a0 ^ a1 ^ mul2(a2) ^ mul3(a3);
        state[i][3] = mul3(a0) ^ a1 ^ a2 ^ mul2(a3);
    }
}
