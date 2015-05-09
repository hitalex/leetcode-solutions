#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

#define N 26

// 表示子节点的列表
struct KidNode{
    char ch;
    KidNode* next;
};

class TrieNode {
public:
    vector<TrieNode*> kids; // 保存所有（可能）子节点
    char path; // 进入当前节点的字符
    string str; // 到达该节点时，已经积累的字符串
    bool is_word; // 判断该节点是否是存储的单词
    // Initialize your data structure here.
    TrieNode() {
        str = "";
        path = '-';
        is_word = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* curr = root;
        int i, j;
        bool flag;
        for(i=0; i<s.length(); i++){
            // 在子节点中查找s[i]
            int num_kids = (curr->kids).size();
            flag = false; // 默认找不到
            for(j=0; j<num_kids; j++){
                if((curr->kids)[j]->path == s[i]){
                    flag = true;
                    break;
                }
            }
            
            if(flag){
                curr = (curr->kids)[j];
                //cout << "Char " << s[i] << " existed, and current: " << curr->str << endl;
            }else{
                TrieNode* p = new TrieNode;
                p->str = s.substr(0, i+1);
                p->path = s[i];
                (curr->kids).push_back(p);
                curr = p;
                //cout << "Add new char " << s[i] << " and current: " << p->str << endl;
            }
        }
        // 表明这是一个插入的单词
        curr->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* curr = root;
        int i, j;
        bool flag;
        for(i=0; i<key.length(); i++){
            // 在子节点中查找s[i]
            int num_kids = (curr->kids).size();
            flag = false; // 默认找不到
            for(j=0; j<num_kids; j++){
                if((curr->kids)[j]->path == key[i]){
                    flag = true;
                    break;
                }
            }
            
            if(flag){
                curr = (curr->kids)[j];
            }else{
                return false;
            }
        }
        
        return curr->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i, j;
        bool flag;
        for(i=0; i<prefix.length(); i++){
            // 在子节点中查找s[i]
            int num_kids = (curr->kids).size();
            flag = false; // 默认找不到
            for(j=0; j<num_kids; j++){
                if((curr->kids)[j]->path == prefix[i]){
                    flag = true;
                    break;
                }
            }
            
            if(flag){
                curr = (curr->kids)[j];
            }else{
                return false;
            }
        }
        
        return true;
    }

private:
    TrieNode* root;
};

int main(){
    // Your Trie object will be instantiated and called as such:
    Trie trie = Trie();
    //insert("abc"),search("abc"),search("ab"),insert("ab"),search("ab"),insert("ab"),search("ab")
    trie.insert("abc");
    cout << trie.search("abc") << endl;
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    
    //cout << trie.startsWith("te") << endl;
    
    //cout << trie.search("ted") << endl;
    
    //cout << trie.startsWith("tea") << endl;
    //cout << trie.startsWith("te") << endl;
    //trie.search("key");
}
