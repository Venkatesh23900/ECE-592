#include <cstdint>

void ShiftRows(uint8_t state[4][4]) {
    
    uint8_t temp[4][4];

    // Copy state to temp
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j] = state[i][j];
        }
    }

    // First row (r = 0) is not shifted
    state[0][0] = temp[0][0];
    state[1][0] = temp[1][0];
    state[2][0] = temp[2][0];
    state[3][0] = temp[3][0];

    // Second row (r = 1) is cyclically left shifted by 1 offset
    state[0][1] = temp[1][1]; 
    state[1][1] = temp[2][1];
    state[2][1] = temp[3][1];
    state[3][1] = temp[0][1];

    // Third row (r = 2) is cyclically left shifted by 2 offsets
    state[0][2] = temp[2][2]; 
    state[1][2] = temp[3][2];
    state[2][2] = temp[0][2];
    state[3][2] = temp[1][2];

    // Fourth row (r = 3) is cyclically left shifted by 3 offsets
    state[0][3] = temp[3][3]; 
    state[1][3] = temp[0][3];
    state[2][3] = temp[1][3];
    state[3][3] = temp[2][3];

}