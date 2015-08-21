#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;

        if(numRows == 0)
            return result;

        vector<int> tmp(1, 1);
        result.push_back(tmp);
        if(numRows == 1){
            return result;
        }

        tmp.push_back(1);
        result.push_back(tmp);
        if(numRows == 2){
            return result;
        }

        int i, j;
        for(i=2; i<numRows; i++){
            vector<int> tmp(1, 1);
            for(j=1; j<i; j++){
                tmp.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }

        return result;

    }
};

int main(){
    Solution solution;

    int numRows = 7;
    vector<vector<int> > result = solution.generate(numRows);

    int i, j;
    for(i=0; i<numRows; i++){
        for(j=0; j<=i; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
