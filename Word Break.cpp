#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

struct WordIndex{
	int start; // 单词的起始位置
	int len; // 单词长度
	WordIndex(int x) : start(x), len(0) {}
};

struct WordNode{
	int start;
	string word;
	WordNode(int x, string s) : start(x), word(s) {}
};

class Solution {
public:
	bool canWordBreak(string s, unordered_set<string> &dict) {
		stack<WordIndex> word_index_stack; // 记录当前每个单词的起始位置index
		word_index_stack.push(WordIndex(0)); // 假设在字符串的第一个位置可以匹配一个单词

		int n = s.length();
		vector<bool> deadend(n+1, false); // 记录哪些位置是deadend
		while (!word_index_stack.empty()){
			WordIndex* pindex = &(word_index_stack.top());
			// 从start开始搜索
			int current_len;
			string wcand; // 候选单词
			for (current_len = pindex->len + 1; pindex->start + current_len <= n; ++current_len){
				// 判断 s[start:end] 是否是一个有效的单词
				wcand = s.substr(pindex->start, current_len);
				unordered_set<string>::const_iterator got = dict.find(wcand);
				
				if (got != dict.end() && !deadend[pindex->start + current_len]) // 找到合法单词，并且当前位置不是一个deadend
					// if found
					break;
			}

			int current_pos = pindex->start + current_len; // 当前的位置
			// 没有找到合法的单词
			if (current_pos > n){
				// we should traceback
				word_index_stack.pop();
				deadend[pindex->start] = true;
				//cout << "回溯..." << endl << endl;
			}
			else{ // s[start:end] is a valid word
				pindex->len = current_len;
				//cout << "当前匹配单词：" << wcand.c_str() << endl;
				//cout << "已经匹配的序列：" << s.substr(0, current_pos).c_str() << endl;

				// 检查是否已经完成
				if (current_pos == n)
					return true;
				else{
					WordIndex next_index(current_pos);
					word_index_stack.push(next_index);
				}
			}
		}

		return false;
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		vector<WordNode> word_list;
		stack<WordIndex> word_index_stack; // 记录当前每个单词的起始位置index
		word_index_stack.push(WordIndex(0)); // 假设在字符串的第一个位置可以匹配一个单词

		int n = s.length();
		vector<bool> deadend(n+1, false); // 记录哪些位置是deadend
		vector<bool> success(n, false); // 记录在每个位置是否产生过成功的句子匹配
		while (!word_index_stack.empty()){
			WordIndex* pindex = &(word_index_stack.top());
			// 从start开始搜索
			int current_len;
			string wcand; // 候选单词
			for (current_len = pindex->len + 1; pindex->start + current_len <= n; ++current_len){
				// 判断 s[start:end] 是否是一个有效的单词
				wcand = s.substr(pindex->start, current_len);
				unordered_set<string>::const_iterator got = dict.find(wcand);

				if (got != dict.end() && !deadend[pindex->start + current_len]) // 找到合法单词，并且当前位置不是一个deadend
					// if found
					break;
			}

			int current_pos = pindex->start + current_len; // 当前的位置
			// 没有找到合法的单词
			if (current_pos > n){
				// we should traceback
				word_index_stack.pop();
				// 造成以下不和谐的原因在于：在进行完成一个单词的匹配时，word_list中还没有加入该单词
				if (! word_list.empty())
					word_list.pop_back();
				// 如果在pindex->start位置产生过成功的句子匹配，则不应该设置为deadend，这里
				// 的回溯应该是主动回溯造成的
				if (!success[pindex->start])
					deadend[pindex->start] = true;
				//cout << "回溯..." << endl << endl;
			}
			else{ // s[start:end] is a valid word
				pindex->len = current_len;
				//cout << "当前匹配单词：" << wcand.c_str() << endl;
				//cout << "已经匹配的序列：" << s.substr(0, current_pos).c_str() << endl;
				word_list.push_back(WordNode(pindex->start, wcand));
				// 检查是否已经完成
				if (current_pos == n){
					string sent = genSentence(word_list);
					result.push_back(sent);
					cout << sent.c_str() << endl;
					// 设置曾经成功生成句子的位置标记
					for (WordNode node : word_list){
						success[node.start] = true;
					}
					// 同样需要回溯，重新查找
					word_index_stack.pop();
					word_list.pop_back(); // remove the last two word if possible
					if (!word_list.empty())
						word_list.pop_back();
				}	
				else{
					WordIndex next_index(current_pos);
					word_index_stack.push(next_index);
				}
			}
		}

		return result;
	}

	// 从单词序列生成加空格的句子
	string genSentence(vector<WordNode> vs){
		string s = vs[0].word;
		for (int i = 1; i < vs.size(); ++i){
			s.push_back(' ');
			s += vs[i].word;
		}

		return s;
	}
};

int main(){
	Solution solution;

	string s = "aaaaaaa";
	unordered_set<string> dict = { "aaaa", "aa", "a" };
	/*
	if (solution.canWordBreak(s, dict))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	*/
	vector<string> result = solution.wordBreak(s, dict);
	for (string s : result){
		cout << s.c_str() << endl;
	}
	cout << endl;

	return 1;
}