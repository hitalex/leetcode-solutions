#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n <= 2)
            return n;
            
        // n >= 3
        // root = a[0]
        int n1 = numTrees(n-1); // 完全是右子树的数量
        // root = a[1]到a[n-2]
        int n2 = 0;
        for(int i=1; i<n-1; i++){
            // root = a[i]
            int t1 = numTrees(i); // 前面有i个数
            int t2 = numTrees(n-i-1); // 后面有n-i-1个数
            n2 += (t1 * t2);
        }
        
        // root=a[n-1]，完全是左子树的情况与n1相同
        int n3 = n1;
        
        return n1 + n2 + n3;
    }
};

int main(){
    Solution solution;
    
    cout << solution.numTrees(5) << endl;
}
