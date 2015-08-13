#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
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
    int myint[] = {0, 1, 2, 3, 5, 7, 8, 10};
    //int myint[] = {0, 1, 1, 2, 3, 5, 5, 7, 8, 10};
    vector<int> a(myint, myint + sizeof(myint)/sizeof(int));

    int n = a.size();
    cout << "Total: " << n << endl;
    cout << "Input s and target:" << endl;

    int target, s;
    cin >> s;
    cin >> target;

    flip(a, 0, n - 1);
    flip(a, 0, n-s-1);
    flip(a, n-s, n-1);

    Solution solution;
    cout << solution.search(a, target) << endl;
}
