#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution{
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length() <= 10)
            return result;
            
        unordered_map<int, int> str_map;
        // 采用对于string的hash函数
        hash<string> hash_fn;
        for(int i=0; i<s.length()-9; i++){
            string tmp = s.substr(i, 10);
            int h = hash_fn(tmp);
            if(str_map.find(h) == str_map.end()){
                str_map[h] = 1;
            }else{
                if(str_map[h] == 1)
                    result.push_back(tmp);
                    
                str_map[h] ++;
            }
        }
        
        return result;
    }
};

/*
// 以下是一种解法，但在leetcode上的结果是Output Limit Exceeded
class Solution {
public:
    map<char, int> num_map;

    Solution(){
        num_map['A'] = 0;
        num_map['D'] = 1;
        num_map['C'] = 2;
        num_map['G'] = 3;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length() <= 10)
            return result;        
        
        // 讲10个长度的A、D、C、G字符串看做长度为10的4进制数，这样一个子串就对应一个数
        set<int> sub_set;
        set<int>::iterator it;
        
        sub_set.insert(string_to_num(s.substr(0, 10))); // 将前10个字符串放入集合中
        int i;
        for(i=1; i<=s.length()-10; i++){
            string tmp = s.substr(i, 10);
            int num = string_to_num(tmp);
            it = sub_set.find(num);
            if(it != sub_set.end()){
                result.push_back(tmp);
                //cout << tmp << endl;
            }else{
                sub_set.insert(num);
            }
        }
        
        return result;
    }
    
    // 讲字符串转换为数字
    int string_to_num(string s){
        int i;
        int num = 0;
        int base = 1;
        for(i=0; i<10; i++){
            num += (num_map[s[i]] * base);
            base *= 4;
        }
        
        return num;
    }
};
*/

int main(){
    Solution solution;
    vector<string> result = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    
}
