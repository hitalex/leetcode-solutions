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
    int total;
    int sumNumbers(TreeNode* root) {
        total = 0;
        calculate(root, 0);
        return total;
    }
    
    void calculate(TreeNode* root, int sum){
    
        if(root == NULL)
            return ;
        
        sum = sum * 10 + root->val;
        
        if(root->left == NULL && root->right == NULL){
            total += sum;
            return ;
        }
        
        calculate(root->left, sum);
        calculate(root->right, sum);
    }
    
};

int main(){
    
    return 1;
}
