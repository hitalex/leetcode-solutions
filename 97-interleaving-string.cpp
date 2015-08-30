#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool flag;
    
    bool isInterleave(string s1, string s2, string s3) {
            
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        /*
        // the dsf solution
        flag = false;
        
        dfs(s1, s2, s3, 0, 0, 0);
        
        return flag;
        */
        
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        vector<bool> pre(n1 + 1, false);
        pre[0] = true; // 为true表示可以到达该处
        for(int i=0, j=0; i<n1 && j<n3; i++, j++){
            // 第一行：只能从左边过来
            if(pre[i] && s1[i] == s3[j]){
                pre[i+1] = true;
            }
        }
        
        // s1作为行，s2作为列
        for(int i=1; i<=n2; i++){
            bool flag = false; // 标记某行是否全部为false
            vector<bool> curr(n1+1, false);
            // 第一个位置：只能从上边过来
            if(pre[0] && s2[i-1] == s3[i-1]){
                curr[0] = true;
                flag = true;
            }
                
            for(int j=1; j<=n1; j++){
                // 考虑从左边过来
                if(curr[j-1] && s1[j-1] == s3[i+j-1]){
                    curr[j] = true;
                    flag = true;
                }
                // 考虑从上边过来
                if(!curr[j] && pre[j] && s2[i-1] == s3[i+j-1]){
                    curr[j] = true;
                    flag = true;
                }
            }
            
            // 如果某行全部为false，则一定无法形成s3
            if(!flag)
                return false;
                
            pre = curr;
        }
        
        return pre[n1];
    }
    
    // p1，p2: s1和s2的index， pos为当前字符串的index
    void dfs(string& s1, string& s2, string& s3, int p1, int p2, int pos){
        if(flag)
            return ;
        
        // 完成匹配
        if(pos == s3.size() && p1 == s1.size() && p2 == s2.size()){
            flag = true;
            return ;
        }
        
        // 测试两种可能：选择s1或者s2
        if(p1 < s1.size() && s1[p1] == s3[pos]){
            dfs(s1, s2, s3, p1+1, p2, pos+1);
        }
        
        if(p2 < s2.size() && s2[p2] == s3[pos]){
            dfs(s1, s2, s3, p1, p2+1, pos+1);
        }
    }
};

int main(){
    Solution solution;
    
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    
    cout << solution.isInterleave(s1, s2, s3) << endl;
    
    cout << solution.isInterleave(s1, s2, s4) << endl;
}
