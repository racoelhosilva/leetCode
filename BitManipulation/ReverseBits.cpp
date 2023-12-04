#include<bits/stdc++.h>
using namespace std;

// O(32)
// Traverse the n
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int _ = 0; _ < 32; _++){
        result <<= 1;
        result |= n & 1;
        n >>= 1;
    }
    return result;
}

// O(5)
// Specific for 32 bits
uint32_t reverseBits(uint32_t n) {
    // Switch the two halves of the 32 bits
    n = (n >> 16) | (n << 16);
    // Switch the 1st/2nd half of each quarter
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    // Switch the 1st/2nd half of each eighth 
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    // Switch the 1st/2nd half of each sixteenth 
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    // Switch the 1st/2nd half of each thirty-secondth 
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}