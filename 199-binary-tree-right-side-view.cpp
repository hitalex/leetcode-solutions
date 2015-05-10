#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        
        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root); // 记录每层需要访问的节点
        while(true){
            // 从左到右依次访问每层的节点，并记录其孩子节点
            TreeNode* right_most_node; // 每层最右边的节点
            queue<TreeNode*> next_layer_queue; // 下层的节点队列
            while(not bfs_queue.empty()){
                right_most_node = bfs_queue.front(); bfs_queue.pop();
                // 分别检查左孩子和右孩子
                if(right_most_node->left != NULL)
                    next_layer_queue.push(right_most_node->left);
                if(right_most_node->right != NULL)
                    next_layer_queue.push(right_most_node->right);
            }
            // 将最右节点的val值放入结果中
            result.push_back(right_most_node->val);
            if(next_layer_queue.size() == 0)
                break;
            else
                bfs_queue = next_layer_queue;
        }
        
        return result;
    }
};
