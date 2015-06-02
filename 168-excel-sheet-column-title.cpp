#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        do{
            int r = n % 26;
            if(r == 0){
                r = 26;
                n = n / 26 - 1;
            }
            else
                n = n / 26;
                
            char ch = 'A' + r - 1;
            s = ch + s;
        }while(n > 0);
        
        return s;
    }
};

int main(){
    Solution s;
    
    cout << s.convertToTitle(28) << endl;
}

