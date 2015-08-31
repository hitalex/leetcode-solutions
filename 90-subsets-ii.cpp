#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i;
        for(i=0; i<=n; i++){
            vector<int> subset;
            dfs(nums, subset, 0, i);
        }
        
        return result;
    }
    
    void dfs(vector<int>& nums, vector<int> subset, int pos, int m){
        if(subset.size() == m){
            result.push_back(subset);
            return ;
        }
        
        int i;
        int n = nums.size();
        for(i=pos; i<n; i++){
            if(i > pos && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            dfs(nums, subset, i+1, m);
            subset.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1); nums.push_back(2); nums.push_back(2);
    
    vector<vector<int> > result = s.subsets(nums);
    
    int i, j;
    for(i=0; i<result.size(); i++){
        vector<int> subset = result[i];
        for(j=0; j<subset.size(); j++){
            cout << subset[j] << " ";
        }
        
        cout << endl;
    }
}
