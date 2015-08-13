#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // the DP solution
    int maxSubArray_DP(vector<int>& nums) {
        long curr_max = 0; // 连续n个数组值相加
        long result = INT_MIN;
        int i;
        for(i=0; i<nums.size(); i++){
            if(curr_max > 0){
                curr_max += nums[i];
            }else{
                curr_max = nums[i];
            }
            if(result < curr_max)
                result = curr_max;
        }
        return result;
    }

    // divide and conqure algorithm
    int maxSubArray(vector<int>& nums){
        return maxsum(nums, 0, nums.size() - 1);
    }

    // 详见编程珠玑，第8章
    int maxsum(vector<int>& nums, int l, int r){
        if(l > r){
            return 0;
        }else if(l == r){
            return max(nums[l], INT_MIN);
        }

        int m = (l + r) / 2;
        int lmax, sum;
        sum = 0;
        lmax = INT_MIN;
        for(int i=m; i>=l; i--){
            sum += nums[i];
            lmax = max(lmax, sum);
        }

        int rmax;
        sum = 0;
        rmax = INT_MIN;
        for(int i=m+1; i<=r; i++){
            sum += nums[i];
            rmax = max(rmax, sum);
        }

        return max(lmax + rmax, max(maxsum(nums, l, m), maxsum(nums, m+1, r)));
    }
};
