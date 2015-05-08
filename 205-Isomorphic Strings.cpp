#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> chrmap;
        map<char, char> reverse_chrmap;
        
        map<char, char>::iterator it;
        map<char, char>::iterator reverse_it;
        
        int i;
        for(i=0; i<s.length(); i++){
            it = chrmap.find(s[i]);
            reverse_it = reverse_chrmap.find(t[i]);
            // 以下分四种情况讨论
            if(it == chrmap.end() && reverse_it == reverse_chrmap.end()){
                // 顺利建立映射
                chrmap[s[i]] = t[i];
                reverse_chrmap[t[i]] = s[i];
            }else if(it != chrmap.end() && reverse_it == reverse_chrmap.end()){
                // s[i]找到映射，但是没有发现有字符映射到t[i]
                return false;
            }else if(it == chrmap.end() && reverse_it != reverse_chrmap.end()){
                return false;
            }else{
                if(chrmap[s[i]] != t[i] || reverse_chrmap[t[i]] != s[i])
                    return false;
            }
        }
        
        return true;
    }
};

int main(){
    Solution solution = Solution();
    
    string s = "ab";
    string t = "aa";
    
    cout << solution.isIsomorphic(s, t) << endl;
}
