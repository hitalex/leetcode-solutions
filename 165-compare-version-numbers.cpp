#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // 删除末尾无意义的“0”
    string remove_trailing_zeros(string v){
        int i = v.length() - 1;
        while(v[i] == '0'){
            i --;
            // 并没有发现类似“3.4.0”的情形，直接返回
            if(i <= 0)
                return v;
        }
        if(v[i] != '.')
            return v;
            
        return v.substr(0, i);
    }
    
    int compareVersion(string version1, string version2) {
        string s1, s2;
        int i = 0;
        int j = 0;
        
        while(true){
            string tmp = remove_trailing_zeros(version1);
            if(tmp == version1)
                break;
            else
                version1 = tmp;
        }
        while(true){
            string tmp = remove_trailing_zeros(version2);
            if(tmp == version2)
                break;
            else
                version2 = tmp;
        }
        
        //cout << version1 << '\n' << version2 << endl;
        
        while(i < version1.length() && j < version2.length()){
            s1 = "";
            s2 = "";
            
            while(i < version1.length() && version1[i] != '.'){
                s1 += version1[i];
                i ++;
            }
            while(j < version2.length() && version2[j] != '.'){
                s2 += version2[j];
                j ++;
            }
            
            int s1_int = atoi(s1.c_str());
            int s2_int = atoi(s2.c_str());
            
            if(s1_int > s2_int)
                return 1;
            else if(s1_int < s2_int)
                return -1;
                
            i ++;
            j ++;
        }
        
        if(i >= version1.length() && j >= version2.length()){
            return 0;
        }else if(i < version1.length() && j >= version2.length()){
            return 1;
        }else
            return -1;
    }
};

int main(){
    Solution solution;
    
    cout << solution.compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000", "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000") << endl;
}
