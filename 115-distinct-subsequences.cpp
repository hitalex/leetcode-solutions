#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        vector<int> prefix(n, 0);
        for(auto c : s){
            for(int i=n-1; i>=0; i--){
                if(c==t[i])
                    prefix[i] = (i > 0 ? prefix[i-1] : 1) + prefix[i];
            }
        }
        
        return prefix.back();
    }
};
