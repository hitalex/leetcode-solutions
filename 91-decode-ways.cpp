#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        // f[i]表示s[0..i]可能有多少中decode方式
        int* f = new int[n];
        
        if(s[0] >= '1' && s[0] <= '9'){
             f[0] = 1;
        }
            
        int i;
        for(i=1; i<=n; i++){
            // s[i]单独编码的个数
            int s1 = 0;
            if(s[i] >= '1' && s[i] <= '9'){
                s1 = f[i-1];
            }
            // 与前一个字符编码
            int s2 = 0;
            if(i - 1 >= 0 && s[i-1] >= '1' && s[i-1] <= '9'){
                int tmp = atoi(s.substr(i-1, 2).c_str());
                if(tmp >= 10 && tmp <= 26){
                    if(i - 2 >= 0)
                        s2 = f[i-2];
                    else
                        s2 = 1;
                }
            }
            
            f[i] = s1 + s2;
        }
        
        return f[n-1];
    }
};

int main(){
    Solution s;
    
    cout << s.numDecodings("122") << endl;
}
