#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

struct WordIndex{
	int start; // ���ʵ���ʼλ��
	int len; // ���ʳ���
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
		stack<WordIndex> word_index_stack; // ��¼��ǰÿ�����ʵ���ʼλ��index
		word_index_stack.push(WordIndex(0)); // �������ַ����ĵ�һ��λ�ÿ���ƥ��һ������

		int n = s.length();
		vector<bool> deadend(n+1, false); // ��¼��Щλ����deadend
		while (!word_index_stack.empty()){
			WordIndex* pindex = &(word_index_stack.top());
			// ��start��ʼ����
			int current_len;
			string wcand; // ��ѡ����
			for (current_len = pindex->len + 1; pindex->start + current_len <= n; ++current_len){
				// �ж� s[start:end] �Ƿ���һ����Ч�ĵ���
				wcand = s.substr(pindex->start, current_len);
				unordered_set<string>::const_iterator got = dict.find(wcand);
				
				if (got != dict.end() && !deadend[pindex->start + current_len]) // �ҵ��Ϸ����ʣ����ҵ�ǰλ�ò���һ��deadend
					// if found
					break;
			}

			int current_pos = pindex->start + current_len; // ��ǰ��λ��
			// û���ҵ��Ϸ��ĵ���
			if (current_pos > n){
				// we should traceback
				word_index_stack.pop();
				deadend[pindex->start] = true;
				//cout << "����..." << endl << endl;
			}
			else{ // s[start:end] is a valid word
				pindex->len = current_len;
				//cout << "��ǰƥ�䵥�ʣ�" << wcand.c_str() << endl;
				//cout << "�Ѿ�ƥ������У�" << s.substr(0, current_pos).c_str() << endl;

				// ����Ƿ��Ѿ����
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
		stack<WordIndex> word_index_stack; // ��¼��ǰÿ�����ʵ���ʼλ��index
		word_index_stack.push(WordIndex(0)); // �������ַ����ĵ�һ��λ�ÿ���ƥ��һ������

		int n = s.length();
		vector<bool> deadend(n+1, false); // ��¼��Щλ����deadend
		vector<bool> success(n, false); // ��¼��ÿ��λ���Ƿ�������ɹ��ľ���ƥ��
		while (!word_index_stack.empty()){
			WordIndex* pindex = &(word_index_stack.top());
			// ��start��ʼ����
			int current_len;
			string wcand; // ��ѡ����
			for (current_len = pindex->len + 1; pindex->start + current_len <= n; ++current_len){
				// �ж� s[start:end] �Ƿ���һ����Ч�ĵ���
				wcand = s.substr(pindex->start, current_len);
				unordered_set<string>::const_iterator got = dict.find(wcand);

				if (got != dict.end() && !deadend[pindex->start + current_len]) // �ҵ��Ϸ����ʣ����ҵ�ǰλ�ò���һ��deadend
					// if found
					break;
			}

			int current_pos = pindex->start + current_len; // ��ǰ��λ��
			// û���ҵ��Ϸ��ĵ���
			if (current_pos > n){
				// we should traceback
				word_index_stack.pop();
				// ������²���г��ԭ�����ڣ��ڽ������һ�����ʵ�ƥ��ʱ��word_list�л�û�м���õ���
				if (! word_list.empty())
					word_list.pop_back();
				// �����pindex->startλ�ò������ɹ��ľ���ƥ�䣬��Ӧ������Ϊdeadend������
				// �Ļ���Ӧ��������������ɵ�
				if (!success[pindex->start])
					deadend[pindex->start] = true;
				//cout << "����..." << endl << endl;
			}
			else{ // s[start:end] is a valid word
				pindex->len = current_len;
				//cout << "��ǰƥ�䵥�ʣ�" << wcand.c_str() << endl;
				//cout << "�Ѿ�ƥ������У�" << s.substr(0, current_pos).c_str() << endl;
				word_list.push_back(WordNode(pindex->start, wcand));
				// ����Ƿ��Ѿ����
				if (current_pos == n){
					string sent = genSentence(word_list);
					result.push_back(sent);
					cout << sent.c_str() << endl;
					// ���������ɹ����ɾ��ӵ�λ�ñ��
					for (WordNode node : word_list){
						success[node.start] = true;
					}
					// ͬ����Ҫ���ݣ����²���
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

	// �ӵ����������ɼӿո�ľ���
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