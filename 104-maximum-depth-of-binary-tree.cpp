
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
    int max_depth;
    
    int maxDepth(TreeNode* root) {
        max_depth = 0;
        
        dfs(root, 1);
        
        return max_depth;
    }
    
    void dfs(TreeNode* root, int curr_depth){
        if(root == NULL)
            return ;
            
        if(curr_depth > max_depth)
            max_depth = curr_depth;
            
        dfs(root->left, curr_depth + 1);
        dfs(root->right, curr_depth + 1);
    }
};
