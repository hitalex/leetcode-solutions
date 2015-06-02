#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int base = 1;
        int i = s.length() - 1;
        int num = 0;
        while(i >= 0){
            int diff = s[i] - 'A' + 1;
            num += (diff * base);
            base *= 26;
            i --;
        }
        
        return num;
    }
};

int main(){
    Solution s;
    cout << s.titleToNumber("AB") << endl;
}
