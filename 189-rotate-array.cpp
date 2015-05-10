#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        if(k == 0)
            return ;
        
        int g = gcd(n, k);
        if(g == 1){
            change_array(nums, 0, k, n);
        }else{
            // 如果k能够被n整除，此时应该分成k组进行处理
            int i;
            for(i=0; i<g; i++){
                change_array(nums, i, k, n/g);
            }
        }
    }
    
    void change_array(vector<int>& nums, int start, int k, int times){
        int curr = start;
        int n = nums.size();
        int last = nums[start];
        while(times--){
            int next = (curr + k) % n;
            int tmp = nums[next];
            nums[next] = last;
            curr = next;
            last = tmp;
        }
    }
    
    // 求得两个数的最大公约数
    int gcd(int a, int b){
        while(b != 0){
            int r = b;
            b = a % b;
            a = r;
        }
        return a;
    }
};

int main(){
    Solution solution;
    int k = 4;
    int myints[] = {1, 2, 3, 4, 5, 6};
    vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
    
    solution.rotate(nums, k);
    
    int i;
    for(i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}
