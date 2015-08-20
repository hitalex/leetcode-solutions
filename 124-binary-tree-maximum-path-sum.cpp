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
    int max_sum = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        
        maxPathSumHelper(root);
        
        return max_sum;
    }
    
    int maxPathSumHelper(TreeNode* root){
        if(!root)
            return 0;
            
        int left = maxPathSumHelper(root->left);
        int right = maxPathSumHelper(root->right);
        
        int closedPathSum = root->val; // 经过root的close路线的最大值
        if(left > 0){
            closedPathSum += left;
        }
        if(right > 0){
            closedPathSum += right;
        }
        
        max_sum = max(closedPathSum, max_sum);
        
        // 考察left+root、right+root或者root自身的情况
        int openPathSum = root->val;
        if(left>0 || right>0){
            openPathSum += (left > right ? left : right)
        }
        
        return openPathSum;
    }
};
