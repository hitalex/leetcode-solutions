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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        
        queue<TreeNode*> Q;
        Q.push(root);
        while(! Q.empty()){
            int num = Q.size();
            vector<int> tmp;
            for(int i=0; i<num; i++){
                TreeNode* p = Q.front(); Q.pop();
                tmp.push_back(p->val);
                
                if(p->left)
                    Q.push(p->left);
                
                if(p->right)
                    Q.push(p->right);
            }
            
            result.insert(result.begin(), tmp);
        }
        
        return result;
    }
};
