class Solution {
public:
	int singleNumber(int A[], int n) {
		int result = 0;
		for (int i = 0; i < 32; ++i){
			int sum = 0;
			for (int j = 0; j < n; ++j){
				// 取每个数字的第i位，并求和
				sum += ((A[j] >> i) & 1);
			}
			// 使那些出现过三次的数字变为0，这样只剩出现一次的数字的第i位
			sum = sum % 3;
			result |= (sum << i);
		}

		return result;
	}
};