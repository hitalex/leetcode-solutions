#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long result = nums[0];
        // 最大和最小只是在正负号之间的区别
        long long curr_max = nums[0];
        long long curr_min = nums[0];
        int i;
        for(i=1; i<nums.size(); i++){
            long long tmp = curr_max;
            curr_max = max(curr_max * nums[i], max(curr_min * nums[i], (long long)nums[i]));
            curr_min = min(tmp * nums[i], min(curr_min * nums[i], (long long)nums[i]));
            if(result < curr_max)
                result = curr_max;
        }
        return result;
    }
};
