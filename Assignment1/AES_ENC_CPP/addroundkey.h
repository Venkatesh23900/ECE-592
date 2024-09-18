#ifndef ADD_ROUND_KEY
#define ADD_ROUND_KEY

#include <cstdint>

void AddRoundKey(uint8_t state[4][4], const uint8_t roundkeys[16]);

#endif // ADD_ROUND_KEY