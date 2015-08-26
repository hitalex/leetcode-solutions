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
    bool isBalanced(TreeNode* root) {
        
        return get_height(root) >= 0;
    }
    
    // if balanced return depth, or else return -1
    int get_height(TreeNode* root){
        if(root == NULL)
            return 0;
            
        int left_height = get_height(root->left);
        if(left_height >=0){
            int right_height = get_height(root->right);
            if(right_height >=0 && std::abs(left_height - right_height) < 2){
                return 1 + max(left_height, right_height);
            }
        }
        
        return -1;
    }
};
