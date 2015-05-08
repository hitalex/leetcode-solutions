#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> num_set; // 保存曾经出现的数字，如果曾经出现，则直接返回false
        int sum = n;
        while(true){
            sum = sum_digit_squared(sum);
            if(sum == 1)
                return true;
            else{
                if(num_set.find(sum) != num_set.end())
                    return false;
                else
                    num_set.insert(sum);
            }
        }
    }
    
    // 计算某个数字各位二次方之和
    int sum_digit_squared(int n){
        int sum = 0;
        while(true){
            int d = n % 10; // 最后一位
            sum += (d*d);
            n = n/10;
            if(n == 0)
                break;
        }
        
        return sum;
    }
};

int main(){
    Solution solution = Solution();
    
    cout << solution.isHappy(25) << endl;
}
