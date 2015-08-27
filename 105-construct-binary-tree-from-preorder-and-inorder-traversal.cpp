
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0)
            return NULL;
        
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    // l1和r1组成区间 [l1, r1), 同理：[l2, r2)
    TreeNode* helper(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2){
        if(l1 >= r1)
            return NULL;
            
        // 在后序遍历中找到根节点
        TreeNode* root = new TreeNode(preorder[l1]);
        // 在中序遍历中，先找到根节点位置，其前半部分为左子树，后半部分为右子树
        int i;
        for(i=l2; i<r2; i++){
            if(inorder[i] == preorder[l1])
                break;
        }
        
        if(i > l2){
            int len = i - l2;
            root->left = helper(preorder, l1 + 1, l1 + 1 + len, inorder, l2, i);
        }
        else
            root->left = NULL;
            
        if(i + 1 < r2){
            int len = r2 - i - 1;
            root->right = helper(preorder, r1 - len, r1, inorder, i + 1, r2);
        }
        else
            root->right = NULL;
            
        return root;
    }
};
