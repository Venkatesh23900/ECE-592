#include <cstdint>
#include <iostream>

// Function to multiply by {02} n times in GF(2^8)
uint8_t multiply(uint8_t x, int n) {
    for (int i = 0; i < n; ++i) {
        if (x & 0x80) {
            x = (x << 1) ^ 0x1b;
        } else {
            x = x << 1;
        }
    }
    return x;
}

// Function to multiply by {0e} in GF(2^8)
uint8_t mb0e(uint8_t x) {
    return multiply(x, 3) ^ multiply(x, 2) ^ multiply(x, 1);
}

// Function to multiply by {0d} in GF(2^8)
uint8_t mb0d(uint8_t x) {
    return multiply(x, 3) ^ multiply(x, 2) ^ x;
}

// Function to multiply by {0b} in GF(2^8)
uint8_t mb0b(uint8_t x) {
    return multiply(x, 3) ^ multiply(x, 1) ^ x;
}

// Function to multiply by {09} in GF(2^8)
uint8_t mb09(uint8_t x) {
    return multiply(x, 3) ^ x;
}

void inv_MixColumns(uint8_t state[4][4]) {
    uint8_t temp[4][4];

    for (int i = 0; i < 4; ++i) {
        temp[i][0] = mb0e(state[i][0]) ^ mb0b(state[i][1]) ^ mb0d(state[i][2]) ^ mb09(state[i][3]);
        temp[i][1] = mb09(state[i][0]) ^ mb0e(state[i][1]) ^ mb0b(state[i][2]) ^ mb0d(state[i][3]);
        temp[i][2] = mb0d(state[i][0]) ^ mb09(state[i][1]) ^ mb0e(state[i][2]) ^ mb0b(state[i][3]);
        temp[i][3] = mb0b(state[i][0]) ^ mb0d(state[i][1]) ^ mb09(state[i][2]) ^ mb0e(state[i][3]);
    }

    // Copy the temp array back to the state array
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] = temp[i][j];
        }
    }
}