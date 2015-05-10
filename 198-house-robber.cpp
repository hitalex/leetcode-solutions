#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        vector<int> f(nums.size(), 0); // f[i]表示抢第i个house的最多money
        vector<int> g(nums.size(), 0); // g[i]表示没有抢第i个house的最多money
        int i;
        f[0] = nums[0];
        g[0] = 0;
        for(i=1; i<nums.size(); i++){
            // 如果不抢第i个house，则必须不能抢第i-1个house
            f[i] = nums[i] + g[i-1];
            // 如果不抢第i个house，那么可以抢或者不抢第i-1个house，两者中取最大值
            g[i] = f[i-1] > g[i-1] ? f[i-1] : g[i-1];
        }
        
        return f[i-1] > g[i-1] ? f[i-1] : g[i-1];
    }
};

int main(){
    Solution solution;
    int a[] = {3, 5, 4, 1, 2, 8};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    cout << solution.rob(nums) << endl;
}
