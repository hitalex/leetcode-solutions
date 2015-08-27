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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)    
            return result;
            
        queue<TreeNode*> Q;
        Q.push(root);
        bool flag = true; // 如果为true，则表示在后添加；否则在前添加元素
        while(! Q.empty()){
            int num = Q.size();
            vector<int> tmp;
            for(int i=0; i<num; i++){
                TreeNode* p = Q.front(); Q.pop();
                if(flag)
                    tmp.push_back(p->val);
                else
                    tmp.insert(tmp.begin(), p->val);
                    
                if(p->left)
                    Q.push(p->left);
                if(p->right)
                    Q.push(p->right);
            }
            
            flag = !flag;
            result.push_back(tmp);
        }
        
        return result;
    }
};
