#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n==1)
            return 0;
            
        int result=0;
        int i;
        for(i=1; i<prices.size(); i++){
            int tmp = prices[i] - prices[i-1];
            if(tmp > 0) {
                result += tmp;
            }
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
