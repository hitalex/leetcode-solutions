#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        uint32_t b;
        int i = 0;
        while(i < 32){
            b = n & 1;
            n = n >> 1;
            m = (m << 1) | b;
            i ++;
        }
        
        return m;
    }
};
