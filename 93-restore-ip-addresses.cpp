#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> result;
    int n;
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        vector<string> ip;
        
        dfs(s, ip, 0);
        
        return result;
    }
    
    // pre记录前一个点的位置，取值范围：0～n-1
    void dfs(string& s, vector<string> ip, int pre){
        int i;
        
        if(ip.size() == 4){
            string addr = "";
            for(i=0; i<ip.size()-1; i++){
                addr += ip[i];
                addr += ".";
            }
            addr += ip[3];
            
            result.push_back(addr);
            
            return ;
        }
        
        for(i= pre + 1; i<=n; i++){
            if(ip.size() == 3)
                i = n;
                
            if(i - pre > 3)
                continue;
                
            string num = s.substr(pre, i - pre);
            int tmp = atoi(num.c_str());
            if(tmp > 255)
                continue;
                
            if((num.size()==3 && tmp>=100) || (num.size() == 2 && tmp>=10) || (num.size()==1 && tmp>=0)){
                ip.push_back(num);
                dfs(s, ip, i);
                ip.erase(ip.end() - 1);
            }
        }
    }
};

int main(){
    Solution solution;
    
    string s = "010010";
    vector<string> result = solution.restoreIpAddresses(s);
    
    for(auto addr : result){
        cout << addr << endl;
    }
}
