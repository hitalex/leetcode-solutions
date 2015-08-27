#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return NULL;
        
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2){
        if(l1 > r1)
            return NULL;
            
        // 在后序遍历中找到根节点
        TreeNode* root = new TreeNode(postorder[r2]);
        // 在中序遍历中，先找到根节点位置，其前半部分为左子树，后半部分为右子树
        int i;
        for(i=l1; i<=r1; i++){
            if(inorder[i] == postorder[r2])
                break;
        }
        
        if(i > l1)
            root->left = helper(inorder, l1, i-1, postorder, l2, l2 + (i-1-l1));
        else
            root->left = NULL;
            
        if(i < r1)
            root->right = helper(inorder, i+1, r1, postorder, r2 - r1 + i, r2 - 1);
        else
            root->right = NULL;
            
        return root;
    }
};

int main(){
    Solution solution;
    
    vector<int> tmp;
    
    solution.buildTree(tmp, tmp);
}
