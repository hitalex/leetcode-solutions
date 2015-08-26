#include <iostream>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* pre;    
    
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        
        pre = NULL; 
        
        pre_order(root);
        
        pre = NULL;
        TreeNode* p = root;
        while(p){
            if(pre != NULL){
                pre->right = p;
                pre->left = NULL;
            }
                
            pre = p;
            p = p->left;
        }
        
    }
    
    // pre：指向前一个树的节点
    void pre_order(TreeNode* root){
        if(root == NULL)
            return ;
        
        // 先将其放入左孩子    
        if(pre != NULL)
            pre->left = root;
            
        // visit the root
        pre = root; // reset the pre
        
        pre_order(root->left);
        pre_order(root->right);
    }
    
};

int main(){
    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;
    
    solution.flatten(root);
    
    TreeNode* p = root;
    while(p){
        cout << p->val << endl;
        p = p->right;
    }
    
}
