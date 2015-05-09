#include <iostream>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n)
            return n;
        else{
            // 最后一位确定为0
            return rangeBitwiseAnd(m>>1, n>>1) << 1;
        }
    }
};

int main(){
    Solution solution;
    
    cout << solution.rangeBitwiseAnd(5, 7) << endl;
}
