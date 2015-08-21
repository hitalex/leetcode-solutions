#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> result;

        numRows ++ ;
        
        if(numRows == 0)
            return result;

        vector<int> tmp(1, 1);
        if(numRows == 1 || numRows == 0){
            return tmp;
        }

        tmp.push_back(1);
        if(numRows == 2){
            return tmp;
        }

        int i, j;
        vector<int> pre = tmp;
        for(i=2; i<numRows; i++){
            vector<int> tmp(1, 1);
            for(j=1; j<i; j++){
                tmp.push_back(pre[j-1] + pre[j]);
            }
            tmp.push_back(1);
            result = tmp;
            pre = tmp;
        }

        return result;

    }
};

int main(){
    Solution solution;

    int numRows = 7;
    vector<int> result = solution.generate(numRows);

    int i, j;
    for(i=0; i<numRows; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}
