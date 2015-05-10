#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        int N = 32;
        while(n > 0){
            if(n & 1 > 0)
                cnt ++;
            n = n >> 1;
        }
        
        return cnt;
    }
};
