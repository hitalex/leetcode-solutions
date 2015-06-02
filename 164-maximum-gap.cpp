#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
            
        int minV = INT_MAX, maxV = INT_MIN; // 记录序列中的最大值和最小值
        int sSize = nums.size();
        // 查找序列中的最大和最小值
        int i;
        for(i=0; i<sSize; i++){
            if(nums[i] > maxV)
                maxV = nums[i];
                
            if(nums[i] < minV)
                minV = nums[i];
        }
        
        // 设置多个bucket，每个桶包含的数字的范围大小都为 (maxV-minV)/(sSize-1)
        int bucket_size = max(1, (maxV - minV) / (sSize - 1)); // 每个桶中数字的范围
        int bucket_num = (maxV - minV) / bucket_size + 1; // 桶的个数
        
        if(bucket_num <=1) return (maxV - minV); 
        
        vector<int> bucket_count(bucket_num, 0); // 初始化每个桶的元素个数为0
        vector<int> bucket_min(bucket_num, INT_MAX); // 存储每个桶的最小元素值，初始化为INT_MAX
        vector<int> bucket_max(bucket_num, INT_MIN); // 存储每个桶的最大元素值，初始化为INT_MIN
        for(i=0; i<sSize; i++){
            int bucket_id = (nums[i] - minV) / bucket_size; // 计算当前元素应该属于哪个bucket
            bucket_count[bucket_id] ++;
            // 分别设置该桶内的最大值和最小值
            bucket_min[bucket_id] = nums[i] > bucket_min[bucket_id] ? bucket_min[bucket_id] : nums[i];
            bucket_max[bucket_id] = nums[i] < bucket_max[bucket_id] ? bucket_max[bucket_id] : nums[i];
        }
        
        int lastmax = minV;
        int maxGap = INT_MIN;
        for(i=0; i<bucket_num; i++){
            if(bucket_count[i] > 0){
                maxGap = max(bucket_min[i] - lastmax, maxGap);
                lastmax = bucket_max[i];
            }
        }
        
        return maxGap;
    }
};

int main(){
    Solution solution;
    int myints[] = {1,1,1,1,1,5,5,5,5,5};
    vector<int> nums(myints, myints + sizeof(myints) / sizeof(int) );
    cout << solution.maximumGap(nums) << endl;
}
