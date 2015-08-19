
#include <iostream>
#include <vector>

using namespace std;

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
    vector<vector<int>> result;
    
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        if(root == NULL)
            return result;
            
        find_path_sum(root, sum, path);
        
        return result;
    }
    
    void find_path_sum(TreeNode* root, int sum, vector<int> path){
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                path.push_back(root->val);
                result.push_back(path);
            }
            
            return ;
        }
        
        path.push_back(root->val);
        if(root->left != NULL){
            find_path_sum(root->left, sum - root->val, path);
        }
        
        if(root->right != NULL){
            find_path_sum(root->right, sum - root->val, path);
        }
        
        return ;
    }
};
