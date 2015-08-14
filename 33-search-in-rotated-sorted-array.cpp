#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return dosearch(nums, target, 0, nums.size() - 1);
    }

    int dosearch(vector<int>& nums, int target, int l, int r){
        if(l < r){
            int m = (l + r) / 2;
            if(nums[m] == target)
                return m;

            if(nums[l] <= nums[m]){
                
            }else{

            }
        }
        return -1;
    }
};

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
    //int myint[] = {0, 1, 2, 3, 5, 7, 8, 10};
    int myint[] = {4,5,6,7,8,1,2,3};
    //int myint[] = {0, 1, 1, 2, 3, 5, 5, 7, 8, 10};
    vector<int> a(myint, myint + sizeof(myint)/sizeof(int));

    int n = a.size();
    cout << "Total: " << n << endl;
    cout << "Input s:" << endl;

    int s;
    cin >> s;
    s = s % n;
    if(s > 0){
        flip(a, 0, n - 1);
        flip(a, 0, n-s-1);
        flip(a, n-s, n-1);
    }
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Input target:" << endl;
    int target;
    cin >> target;
    Solution solution;
    cout << solution.search(a, target) << endl;
}
