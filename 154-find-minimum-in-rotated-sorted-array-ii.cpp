#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 数组中可能存在重复数字
    int findMin(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }

    int search(std::vector<int>& nums, int left, int right){
        if(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]){
                return search(nums, mid+1, right);
            }else if(nums[mid] == nums[right]){
                return min(search(nums, mid+1, right), search(nums, left, mid));
            }else{
                return search(nums, left, mid);
            }
        }else
            return nums[right];
    }
};

// 讲a[start, end]取反
void flip(vector<int>& a, int start, int end){
    while(start < end){
        int tmp = a[end];
        a[end] = a[start];
        a[start] = tmp;
        start ++;
        end --;
    }
}

int main(){
    int myint[] = {0, 1, 1, 2, 3, 5, 5, 7, 8, 10};
    vector<int> a(myint, myint + sizeof(myint)/sizeof(int));

    int s = 7;
    int n = a.size();
    flip(a, 0, n - 1);
    flip(a, 0, n-s-1);
    flip(a, n-s, n-1);

    Solution solution;
    cout << solution.findMin(a) << endl;
}
