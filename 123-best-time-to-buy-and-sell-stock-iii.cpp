#include <iostream>

using namespace std;

class Solution {
public:
    /*
    Ref: https://leetcode.com/discuss/48151/my-c-solution-o-n-time-o-1-space-8ms
    states[][0]: one buy
    states[][1]: one buy, one sell
    states[][2]: two buys, one sell
    states[][3]: two buy, two sells
    */
    int maxProfit(vector<int>& prices) {
        // 截至到当前时间点，对股票的四种操作行为
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0};
        int curr = 0, next = 1; // 用于状态转换
        for(int i=0; i<prices.size(); i++){
            states[next][0] = max(states[curr][0], -prices[i]);
            states[next][1] = max(states[curr][1], states[curr][0]+prices[i]);
            states[next][2] = max(states[curr][2], states[curr][1]-prices[i]);
            states[next][3] = max(states[curr][3], states[curr][2]+prices[i]);
            swap(next, curr);
        }

        return max(states[curr][1], states[curr][3]);
    }
};
