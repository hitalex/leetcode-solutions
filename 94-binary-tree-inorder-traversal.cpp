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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
            
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top(); s.pop();
            
            result.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return result;
    }
};
