#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(beginWord);
        wordDict.insert(endWord);
        
		queue<string> toVisit; // 保存所有待展开的节点
		addNextWord(beginWord, wordDict, toVisit);
		int dis = 2;
		int i;
		while(! toVisit.empty()){
		    int num = toVisit.size();
		    for(i=0; i<num; i++){
		        string word = toVisit.front(); toVisit.pop();
		        if(word == endWord){
		            return dis;
		        }else{
		            addNextWord(word, wordDict, toVisit);
		        }
		    }
		    
		    dis ++;
		}
		
		return 0;
    }
    
    void addNextWord(string word, unordered_set<string>& wordDict, queue<string>& toVisit){
        wordDict.erase(word);
        int wlen = word.size();
        for(int i=0; i<wlen; i++){
            for(char ch='a'; ch<='z'; ++ch){
                string new_word = word;
                new_word[i] = ch;
                if(wordDict.find(new_word) != wordDict.end()){
                    toVisit.push(new_word);
                    wordDict.erase(new_word);
                }
            }
        }
    }
};

int main(){
    string beginWord = "a";
    string endWord = "c";
    
    unordered_set<string> wordDict;
    wordDict.insert("a");
    wordDict.insert("b");
    wordDict.insert("c");
    
    Solution solution;
    
    cout << solution.ladderLength(beginWord, endWord, wordDict) << endl;
    
    return 1;
}
