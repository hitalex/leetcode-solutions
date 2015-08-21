#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int row = triangle.size();
        if(row == 1)
            return triangle[0][0];

        vector<int> pre(row, 0);
        vector<int> curr(row, 0);
        int i, j;
        pre[0] = triangle[0][0]; // top row
        cout << pre[0] << endl;
        for(i=1; i<row; i++){
            curr[0] = pre[0] + triangle[i][0];
            cout << curr[0] << " ";
            for(j=1; j<=i; j++){
                if(j == i){
                    curr[j] = pre[j-1] + triangle[i][j];
                }else{
                    curr[j] = min(pre[j-1], pre[j]) + triangle[i][j];
                }
                cout << curr[j] << " ";
            }
            cout << endl;

            swap(curr, pre);
        }

        int min_sum = pre[0];
        for(i=1; i<row; i++){
            if(pre[i] < min_sum){
                min_sum = pre[i];
            }
        }

        return min_sum;
    }
};

int main(){
    fstream f("input.txt", fstream::in);
    int row;
    f >> row;
    int i, j;
    vector<vector<int> > triangle;
    for(i=0; i<row; i++){
        vector<int> line;
        for(j=0; j<=i; j++){
            int e;
            f >> e;
            line.push_back(e);
        }
        triangle.push_back(line);
    }

    Solution solution;

    cout << solution.minimumTotal(triangle) << endl;
}
