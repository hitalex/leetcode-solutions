class Solution {
public:
	int singleNumber(int A[], int n) {
		int result = 0;
		for (int i = 0; i < 32; ++i){
			int sum = 0;
			for (int j = 0; j < n; ++j){
				// ȡÿ�����ֵĵ�iλ�������
				sum += ((A[j] >> i) & 1);
			}
			// ʹ��Щ���ֹ����ε����ֱ�Ϊ0������ֻʣ����һ�ε����ֵĵ�iλ
			sum = sum % 3;
			result |= (sum << i);
		}

		return result;
	}
};