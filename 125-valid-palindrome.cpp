#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlphabet(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
            return true;
        else
            return false;
    }
    
    bool isNumeric(char ch){
        if(ch>='0' && ch<='9')
            return true;
        else
            return false;
    }

    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
            
        int head = 0;
        int tail = s.size() - 1;
        while(true){
            while(! isAlphabet(s[head]) && !isNumeric(s[head]) && head < tail)
                head ++;
                
            while(! isAlphabet(s[tail]) && !isNumeric(s[tail]) && head < tail)
                tail --;
                
            if(head >= tail)
                break;
            
            char left = s[head];
            char right = s[tail];
            if(isAlphabet(left))
                left = tolower(left);
            
            if(isAlphabet(right))
                right = tolower(right);
                
            if(left != right)
                return false;
            else{
                head ++;
                tail --;
            }
        }
        
        return true;
    }
};

int main(){
    Solution solution;
    
    cout << solution.isPalindrome("ab2a") << endl;
}
