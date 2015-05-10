#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n==1)
            return 0;
            
        vector<int> min(n, 0); // min[i]表示[0, i)之间的最小值
        vector<int> max(n, 0); // max[i]表示[i, n)之间的最大值
        
        min[0] = prices[0];
        max[n-1] = prices[n-1];
        int i;
        for(i=1; i<n-1; i++){
            min[i] = prices[i] > min[i-1] ? min[i-1] : prices[i];
        }
        for(i=n-2; i>0; i--){
            max[i] = prices[i] > max[i+1] ? prices[i] : max[i+1];
        }
        
        int result = 0;
        for(i=0; i<n-1; i++){
            if(result < (max[i+1] - min[i]))
                result = max[i+1] - min[i];
        }
        
        return result;
    }
};

int main(){
    Solution solution;
    int a[] = {1,2,4};
    vector<int> prices(a, a + sizeof(a) / sizeof(int));
    cout << solution.maxProfit(prices) << endl;
}
