#include <iostream>
#include <iomanip>
#include <cstdint>
#include "inv_sbox.h"
#include "inv_subbytes.h"
#include "inv_shiftrows.h"
#include "inv_mixcolumns.h"
#include "addroundkey.h"

// Print the state
void printState(const uint8_t state[4][4], const std::string& label) {
    std::cout << label << ": ";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)state[i][j];
        }
    }
    std::cout << std::endl;
}

// Print round keys
void printRoundKey(const uint8_t roundKey[16], int rnd) {
    std::cout << "Round[" << std::dec << rnd << "] Key: ";
    for (int i = 0; i < 16; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)roundKey[i];
    }
    std::cout << std::endl;
}

void AES_Decrypt(uint8_t state[4][4], const uint8_t roundKeys[11][16]) {
    // Print initial ciphertext and final round key
    printState(state, "Ciphertext");
    printRoundKey(roundKeys[10], 10);

    // Initial round
    AddRoundKey(state, roundKeys[10]);

    // Main rounds
    for (int Nr = 9; Nr > 0; Nr--) {
        std::cout << "------------------------------------------------------------------------" << std::endl;
        std::cout << "Round[" << std::dec << Nr << "].start: ";
        printState(state, "");

        // Print round key for this round
        printRoundKey(roundKeys[Nr], Nr);

        // Inverse ShiftRows
        std::cout << "Input to InvShiftRows: ";
        printState(state, "");
        inv_ShiftRows(state);
        std::cout << "Output to InvShiftRows: ";
        printState(state, "");

        // Inverse SubBytes
        std::cout << "Input to InvSubBytes: ";
        printState(state, "");
        inv_SubBytes(state);
        std::cout << "Output to InvSubBytes: ";
        printState(state, "");

        // AddRoundKey
        std::cout << "Input to AddRoundKey: ";
        printState(state, "");
        AddRoundKey(state, roundKeys[Nr]);
        std::cout << "Output to AddRoundKey: ";
        printState(state, "");

        // Inverse MixColumns
        std::cout << "Input to InvMixCols: ";
        printState(state, "");
        inv_MixColumns(state);
        std::cout << "Output to InvMixCols: ";
        printState(state, "");
    }

    // Final round
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "Round[0].start: ";
    printState(state, "");

    // Print initial round key
    printRoundKey(roundKeys[0], 0);

    // Inverse ShiftRows
    std::cout << "Input to InvShiftRows: ";
    printState(state, "");
    inv_ShiftRows(state);
    std::cout << "Output to InvShiftRows: ";
        printState(state, "");

    // Inverse SubBytes
    std::cout << "Input to InvSubBytes: ";
    printState(state, "");
    inv_SubBytes(state);
    std::cout << "Output to InvSubBytes: ";
    printState(state, "");

    // Final AddRoundKey
    std::cout << "Input to AddRoundKey: ";
    printState(state, "");
    AddRoundKey(state, roundKeys[0]);
    std::cout << "Plaintext";
    printState(state, "");
}

int main() {
    uint8_t ciphertext[4][4] = {
        {0x69, 0xc4, 0xe0, 0xd8},
        {0x6a, 0x7b, 0x04, 0x30},
        {0xd8, 0xcd, 0xb7, 0x80},
        {0x70, 0xb4, 0xc5, 0x5a}
    };

    // Define round keys
    uint8_t roundKeys[11][16] = {
        {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f},
        {0xd6, 0xaa, 0x74, 0xfd, 0xd2, 0xaf, 0x72, 0xfa, 0xda, 0xa6, 0x78, 0xf1, 0xd6, 0xab, 0x76, 0xfe},
        {0xb6, 0x92, 0xcf, 0x0b, 0x64, 0x3d, 0xbd, 0xf1, 0xbe, 0x9b, 0xc5, 0x00, 0x68, 0x30, 0xb3, 0xfe},
        {0xb6, 0xff, 0x74, 0x4e, 0xd2, 0xc2, 0xc9, 0xbf, 0x6c, 0x59, 0x0c, 0xbf, 0x04, 0x69, 0xbf, 0x41},
        {0x47, 0xf7, 0xf7, 0xbc, 0x95, 0x35, 0x3e, 0x03, 0xf9, 0x6c, 0x32, 0xbc, 0xfd, 0x05, 0x8d, 0xfd},
        {0x3c, 0xaa, 0xa3, 0xe8, 0xa9, 0x9f, 0x9d, 0xeb, 0x50, 0xf3, 0xaf, 0x57, 0xad, 0xf6, 0x22, 0xaa},
        {0x5e, 0x39, 0x0f, 0x7d, 0xf7, 0xa6, 0x92, 0x96, 0xa7, 0x55, 0x3d, 0xc1, 0x0a, 0xa3, 0x1f, 0x6b},
        {0x14, 0xf9, 0x70, 0x1a, 0xe3, 0x5f, 0xe2, 0x8c, 0x44, 0x0a, 0xdf, 0x4d, 0x4e, 0xa9, 0xc0, 0x26},
        {0x47, 0x43, 0x87, 0x35, 0xa4, 0x1c, 0x65, 0xb9, 0xe0, 0x16, 0xba, 0xf4, 0xae, 0xbf, 0x7a, 0xd2},
        {0x54, 0x99, 0x32, 0xd1, 0xf0, 0x85, 0x57, 0x68, 0x10, 0x93, 0xed, 0x9c, 0xbe, 0x2c, 0x97, 0x4e},
        {0x13, 0x11, 0x1d, 0x7f, 0xe3, 0x94, 0x4a, 0x17, 0xf3, 0x07, 0xa7, 0x8b, 0x4d, 0x2b, 0x30, 0xc5}
    };

    AES_Decrypt(ciphertext, roundKeys);

    return 0;
}
