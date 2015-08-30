#include <iostream>
#include <vector>

using namespace std;

// * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        
        return helper(0, n-1);
    }
    
    // 生成l和r之间的所有子树
    vector<TreeNode*> helper(int l, int r){
        vector<TreeNode*> result;
        if(l > r){
            result.push_back(NULL);
            return result;
        }
            
        if(l == r){
            TreeNode* root = new TreeNode(l);
            root->left = NULL;
            root->right = NULL;
            result.push_back(root);
            return result;
        }
        
        for(int i=l; i<=r; i++){
            vector<TreeNode*> kids_left = helper(l, i-1);
            vector<TreeNode*> kids_right = helper(i+1, r);
            for(auto left : kids_left)
                for(auto right : kids_right){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
        }
        
        return result;
    }
};

int main(){
    Solution solution;
    
    cout << solution.generateTrees(3).size() << endl;
}
