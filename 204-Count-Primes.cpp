#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // 不超过n的质数
        if(n <= 2)
            return 0;
            
        int* a = (int*)malloc(sizeof(int) * n);
        int i;
        // a[i]表示i在筛中
        for(i=0; i<n; i++){
            a[i] = 1;
        }
        
        int num_primes = 0;
        int last_prime = 0; // 上一个质数
        a[0] = 0;
        a[1] = 0;
        while(true){
            // 找到a数组最左侧在筛中的质数
            for(i=last_prime+1; i<n; i++)
                if(a[i] != 0)
                    break;
            if(i >= n)
                return num_primes;
            
            // 在原数组中删除所有curr_prime的倍数
            int curr_prime = i;
            num_primes += 1;
            int max;
            if(n%curr_prime == 0)
                max = n/curr_prime - 1;
            else
                max = n/curr_prime;
                
            for(i=curr_prime; i<=max; i++){
                a[curr_prime * i] = 0;
            }
            last_prime = curr_prime;
        }
    }
};

int main(){
    Solution solution = Solution();
    
    cout << solution.countPrimes(6) << endl;
}
