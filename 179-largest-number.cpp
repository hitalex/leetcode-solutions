#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::stable_sort(nums.begin(), nums.end(), compareGreater);
        if (!nums.empty() && nums[0]==0)
        {
            return "0";
        }
        string val;
        for (auto v : nums)
        {
            val += std::to_string(v);
        }
        return val;
    }


    static bool  compareGreater(int lhs, int rhs){
        return to_string(lhs) + to_string(rhs) > to_string(rhs) + to_string(lhs);
    }
};

int main(){
    Solution solution;
    vector<int> nums;
    nums.push_back(9525); nums.push_back(95); nums.push_back(4);
    
    cout << solution.largestNumber(nums) << endl;
}
