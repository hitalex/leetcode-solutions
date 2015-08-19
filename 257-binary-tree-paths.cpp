#include <cstdio>
#include <string>
#include <vector>

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

    vector<string> result;
    char buffer[32];
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        
        if(root == NULL)
            return result;
            
        find_path_string(root, s);
        
        return result;
    }
    
    void find_path_string(TreeNode* root, string path){
        
        if(root->left == NULL && root->right == NULL){
            sprintf(buffer, "%d", root->val);
            path = path + buffer;
            result.push_back(path);
            return ;
        }
        
        sprintf(buffer, "%d->", root->val);
        path += buffer;
        
        if(root->left != NULL){
            find_path_string(root->left, path);
        }
        
        if(root->right != NULL){
            find_path_string(root->right, path);
        }
        
        return ;
    }
};

int main(){
    return 1;
}
