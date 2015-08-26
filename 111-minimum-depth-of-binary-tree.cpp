
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> Q;
        
        int curr_depth = 0;
        Q.push(root);
        
        while(! Q.empty()){
            int num = Q.size(); // 当前层的节点数
            int i;
            for(i=0; i<num; i++){
                TreeNode* p = Q.front(); Q.pop();
                if(p->left == NULL && p->right == NULL)
                    return curr_depth;
                    
                if(p->left)
                    Q.push(p->left);
                if(p->right)
                    Q.push(p->right);
            }
            
            curr_depth ++;
        }
        
        // should never reach here
    }
};
