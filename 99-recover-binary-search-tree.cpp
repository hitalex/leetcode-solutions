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
    TreeNode* pre; // 前一个访问节点
    TreeNode* first; // 交换元素的第一个
    TreeNode* second; // 交换元素的第二个
    
    void recoverTree(TreeNode* root) {
        if(root == NULL)    
            return ;
            
        pre = NULL;
        first = NULL;
        second = NULL;
        
        dfs(root);
        
        // 交换两个节点的值
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    
    void dfs(TreeNode* root){
        if(root == NULL)
            return ;
            
        dfs(root->left);
        
        // 访问root节点
        if(pre != NULL && pre->val > root->val){
            if(first == NULL){ // 遇到第一个被调换的元素
                first = pre;
                second = root; // 如果两个调换的元素相邻，则应采用该设置
            }else{
                // 遇到第二被调换的元素，此时两个元素不相邻
                second = root;
            }
        }
        
        pre = root;
        
        dfs(root->right);
    }
};
