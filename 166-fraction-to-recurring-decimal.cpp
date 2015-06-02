#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long lnumerator = numerator;
        long ldenominator = denominator;
        
        string result = "";
        if(lnumerator == 0)
            return "0";
        
        if((lnumerator < 0 && ldenominator > 0) || (lnumerator > 0 && ldenominator < 0)){
            result += '-';
        }
        
        lnumerator = abs(lnumerator);
        ldenominator = abs(ldenominator);
        cout << lnumerator << " " << ldenominator << endl;
        
        if(lnumerator == ldenominator)
            return "1";
        else if(lnumerator > ldenominator){
            long r = lnumerator / ldenominator;
            result += to_string(r);
            if(lnumerator % ldenominator == 0)
                return result;
                
            result += '.';
            lnumerator = lnumerator % ldenominator;
        }else{
            result += '0';
            result += '.';
        }
        
        int zpos = result.length();
        // assert lnumerator !=0 and lnumerator < ldenominator
        // 计算小数部分
        long a = lnumerator;
        long r;
        vector<long> modlist; // 记录所有曾经出现的余数
        while(true){
            modlist.push_back(a);
            a *= 10;
            r = a / ldenominator;
            long tmp = a % ldenominator;
            if(tmp == 0){
                result += to_string(r);
                return result;
            }
            
            result += to_string(r);
            //cout << a << '/' << ldenominator << '=' << r << endl;
            // 检查是否出现循环节
            int i;
            for(i = 0; i < modlist.size(); i++){
                if(modlist[i] == tmp)
                    break;
            }
            if(i < modlist.size()){
                // 确实发现循环节
                result.insert(i+zpos, "(");
                result += ')';
                return result;
            }
            
            a = tmp;
        }
    }
};

int main(){
    Solution s;
    cout << s.fractionToDecimal(-2147483648, 1) << endl;
}
