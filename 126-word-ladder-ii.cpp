#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordDict) {
        
        vector<vector<string> > result;
        
        wordDict.insert(beginWord);
        wordDict.insert(endWord);
        
		queue<string> toVisit; // 保存所有待展开的节点
		queue<vector<string> > pathQueue;
		vector<string> path;
		path.push_back(beginWord);
		pathQueue.push(path);
		
		addNextWord(beginWord, wordDict, toVisit, path, pathQueue);
		int dis = 2;
		int i;
		while(! toVisit.empty()){
		    int num = toVisit.size();
		    for(i=0; i<num; i++){
		        string word = toVisit.front(); toVisit.pop();
		        vector<string> path = pathQueue.front(); pathQueue.pop();
		        if(word == endWord){
		            vector<string> new_path = path;
		            new_path.push_back(word);
		            result.push_back(new_path);
		        }else{
		            addNextWord(word, wordDict, toVisit, path, pathQueue);
		        }
		    }
		    
		    dis ++;
		}
		
		return result;
    }
    
    void addNextWord(string word, unordered_set<string>& wordDict, queue<string>& toVisit, vector<string> path, queue<vector<string> >& pathQueue){
        wordDict.erase(word);
        int wlen = word.size();
        for(int i=0; i<wlen; i++){
            for(char ch='a'; ch<='z'; ++ch){
                string new_word = word;
                new_word[i] = ch;
                if(wordDict.find(new_word) != wordDict.end()){
                    toVisit.push(new_word);
                    wordDict.erase(new_word);
                    
                    vector<string> new_path = path;
                    new_path.push_back(new_word);
                    pathQueue.push(new_path);                    
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
    
    vector<vector<string> > path_list = solution.findLadders(beginWord, endWord, wordDict);
    
    int count = path_list.size();
    for(int i=0; i<count; i++){
        vector<string> path = path_list[i];
        for(int j=0; j<path.size(); j++){
            cout << path[j] << " -> ";
        }
        cout << endl;
    }
    
    return 1;
}
