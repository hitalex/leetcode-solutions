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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return helper(nums, 0, n-1);
    }
    
    // 
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l > r)
            return NULL;
            
        int m = (l + r) / 2;
        TreeNode* p = new TreeNode(nums[m]);
        p->left = helper(nums, l, m-1);
        p->right = helper(nums, m+1, r);
        
        return p;
    }
};
