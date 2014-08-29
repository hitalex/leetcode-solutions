#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth = 4; // depth of the binary tree
int max_nodes = 16;
// the first element is a stum
int a[16] = {-1, 5, 1, 6, 0, 3, -1, 8, -1, -1, 2, 4, -1, -1, 7, -1}; // negative values indicate empty nodes

class Solution {
public:
	// �ǵݹ�汾
	// �������
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> s; // ��ջ�洢��һ����Ҫ���ʵ�Ԫ��
		if (root == NULL){
			return result;
		}

		s.push(root);
		while (!s.empty()){
			TreeNode* p = s.top();
			s.pop();
			result.push_back(p->val);

			if (p->right != NULL){
				s.push(p->right);
			}

			if (p->left != NULL){
				s.push(p->left);
			}
		}

		return result;
	}

	// �������
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode*> s;
		TreeNode* current = root;
		bool done = false;
		vector<int> result;
		while (!done){
			if (current){
				s.push(current);
				current = current->left;
			}
			else{
				if (s.empty()){
					done = true;
				}
				else{
					current = s.top();
					s.pop();
					result.push_back(current->val);
					current = current->right;
				}
			}
		}

		return result;
	}
	
	// �������
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == NULL){
			return result;
		}

		stack<TreeNode*> s;
		s.push(root);
		TreeNode* pre = NULL; // previously visited node
		while (!s.empty()){
			TreeNode* curr = s.top();
			// traversing down the tree
			if (!pre || pre->left == curr || pre->right == curr){
				if (curr->left){
					s.push(curr->left);
				}
				else if (curr->right){
					s.push(curr->right);
				}
				else{
					result.push_back(curr->val);
					s.pop();
				}
			}
			// traversing up the tree from the left child
			else if (curr->left == pre){
				if (curr->right){
					s.push(curr->right);
				}
				else{
					result.push_back(curr->val);
					s.pop();
				}
			}
			// traversing up the tree from the right child
			else if (curr->right == pre){
				result.push_back(curr->val);
				s.pop();
			}

			pre = curr;
		}

		return result;
	}

	// �ݹ�汾
	// �������
	void preorderTraversal_recursive(TreeNode* pnode){
		if (pnode == NULL){
			return;
		}

		cout << pnode->val << ' ';
		preorderTraversal_recursive(pnode->left);
		preorderTraversal_recursive(pnode->right);
	}
};

// �����������й��������
void createBinaryTree(TreeNode* parent, int index){
	if (index * 2 <= max_nodes && a[index*2] >= 0){
		TreeNode* left = new TreeNode(a[index*2]);
		parent->left = left;
		createBinaryTree(left, index * 2);
	}

	if (index * 2 + 1 <= max_nodes && a[index * 2+1] >= 0){
		TreeNode* right = new TreeNode(a[index * 2 + 1]);
		parent->right = right;
		createBinaryTree(right, index * 2 + 1);
	}
}

int main(){
	// ���ɶ�����
	TreeNode root_node(a[1]);
	TreeNode* root = &root_node;
	createBinaryTree(root, 1);

	Solution solution;
	// ��ӡ���ɵĶ�����
	//solution.preorderTraversal_recursive(root);

	// �ǵݹ��������
	//vector<int> result = solution.preorderTraversal(root);

	// �ǵݹ��������
	vector<int> result = solution.postorderTraversal(root);

	for (int e : result){
		cout << e << ' ';
	}
	cout << endl;

	return 0;
}