#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pre = nums[0];
        int count = 1;
        int i;
        for(i=1; i<nums.size(); i++){
            if(nums[i] == pre)
                count ++;
            else{
                count --;
                if(count <= 0){
                    pre = nums[i];
                    count = 1;
                }
            }
        }
        
        return pre;
    }
};
