#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode*> s; // 存储下一个访问节点
    
    BSTIterator(TreeNode *root) {
        // 先找到最小的
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = s.top(); s.pop();
        int ret = p->val;
        if(p->right){
            find_left(p->right);
        }
        
        return ret;
    }
    
    void find_left(TreeNode* p){
        while(p){
            s.push(p);
            if(p->left){
                p = p->left;
            }
            else
                break;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
