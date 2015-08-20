#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:

    string beginWord;
    string endWord;
    unordered_set<string> wordDict;
    
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordDict) {

        vector<vector<string> > result;

        wordDict.insert(beginWord);
        wordDict.insert(endWord);
        
        this->beginWord = beginWord;
        this->endWord = endWord;
        this->wordDict = wordDict;

		queue<string> toVisit; // 保存所有待展开的节点
		queue<vector<string> > pathQueue;
		unordered_map<string, vector<string> > prePath; // 将string映射到其path
		
		vector<string> path;
		path.push_back(beginWord);
		prePath[beginWord] = path;
		
		vector<string> wlist = addNextWord(beginWord, toVisit, prePath);
		// 删除第一层的所有新加入的单词
		removeWords(wlist);
		
		int dis = 2;
		int shortest_dis = INT_MAX;
		int i;
		while(! toVisit.empty()){
		    int num = toVisit.size();
		    vector<string> wlist;
		    for(i=0; i<num; i++){
		        string word = toVisit.front(); toVisit.pop();
		        vector<string> path = prePath[word];
                /*
                cout << "Pop word: " << word << endl;
                cout << "Pop path: " << endl;
                for(int j=0; j<path.size(); j++)
                    cout << path[j] << " -> ";
                cout << endl;
                */
		        if(word == endWord){
		            shortest_dis = min(dis, shortest_dis);
		            if(path.size() <= shortest_dis) // 一旦得到不是最短路径，则可以直接返回
		                result.push_back(path);
		            else
		                return result;
		        }else{
		            vector<string> tmp = addNextWord(word, toVisit, prePath);
		            wlist.insert(wlist.end(), tmp.begin(), tmp.end());
		        }
		    }
		    
		    // 删除在该层中新扩展的单词
		    removeWords(wlist);

		    dis ++;
		}

		return result;
    }

    vector<string> addNextWord(string word, queue<string>& toVisit, unordered_map<string, vector<string> >& prePath){
        vector<string> path = prePath[word];
        vector<string> res;
        int wlen = word.size();
        for(int i=0; i<wlen; i++){
            for(char ch='a'; ch<='z'; ++ch){
                string new_word = word;
                new_word[i] = ch;
                // 必须在字典中，而且不在该路径上
                if(wordDict.find(new_word) != wordDict.end()){
                    toVisit.push(new_word);
                    
                    vector<string> new_path = path;
                    new_path.push_back(new_word);
                    
                    prePath[new_word] = new_path;
                    res.push_back(new_word);
                    /*
                    cout << "Add word: " << new_word << endl;
                    cout << "Add new path: " << endl;
                    int j;
                    for(j=0; j<new_path.size(); j++){
                        cout << new_path[j] << " -> " ;
                    }
                    cout << endl;
                    */
                }
            }
        }
        
        return res;
    }
    
    void removeWords(vector<string> words){
        for(auto w : words){
            wordDict.erase(w);
        }
    }
};

int main(){
    string beginWord = "red";
    string endWord = "tax";

    unordered_set<string> wordDict;
    wordDict.insert("ted");
    wordDict.insert("tex");
    wordDict.insert("red"); 
    wordDict.insert("tax"); 
    wordDict.insert("tad");
    wordDict.insert("den");
    wordDict.insert("rex");
    wordDict.insert("pee");

    Solution solution;

    vector<vector<string> > path_list = solution.findLadders(beginWord, endWord, wordDict);

    cout << "Result: " << endl;
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
