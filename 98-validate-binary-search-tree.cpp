/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pre;
    bool flag;
    
    bool isValidBST(TreeNode* root) {
        pre = NULL;
        flag = true;
        
        dfs(root);
        
        return flag;
    }
    
    void dfs(TreeNode* root){
        if(!flag)
            return ;
            
        if(!root)
            return;
            
        dfs(root->left);
        
        if(pre && pre->val >= root->val){
            flag = false;
        }
        
        pre = root;
        
        dfs(root->right);
    }
};
