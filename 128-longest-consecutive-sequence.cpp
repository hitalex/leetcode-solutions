class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 将所有的元素添加到set中
		unordered_set<int> record(nums.begin(), nums.end());

		int res = 0; // 保存当前最长的序列长度
		for(unsigned int i = 0; i<nums.size(); i++){
			int e = nums[i];
			if(record.find(e) == record.end())
				continue;

			int count = 1;
			record.erase(e);
			// 向e的左边查找
			while(record.find(--e) != record.end()){
				count += 1;
				record.erase(e);
			}
			// 向e的右边查找
			e = nums[i];
			while(record.find(++e) != record.end()){
				count += 1;
				record.erase(e);
			}

			res = max(res, count);
		}

		return res;
    }
};
