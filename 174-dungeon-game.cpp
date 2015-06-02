#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// 对应每个dungeon中的每个格子
// 定义最佳路径为lowest值最大的路径
struct Node{
    int from; // from=0表示从左边过来，from=1表示从上边
    int lowest; // 到当前节点的路径的最低health值
    int curr; // 记录当前路径的health值
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if(dungeon.size() == 0)
            return 0;
            
        int M = dungeon.size();
        int N = dungeon[0].size();
        if(N == 0)
            return 0;
            
        int i, j;
        for(i=M-1; i>=0; i--){
            for(j=N-1; j>=0; j--){
                if(i==M-1 && j==N-1){
                    ;
                }else if(i == M-1){
                    // 考虑从右边过来
                    if(dungeon[i][j+1] < 0)
                        dungeon[i][j] += dungeon[i][j+1];
                }else if(j == N-1){
                    // 考虑从下边过来
                    if(dungeon[i+1][j] < 0)
                        dungeon[i][j] += dungeon[i+1][j];
                }else{
                    int tmp = max(dungeon[i][j+1], dungeon[i+1][j]);
                    if(tmp < 0)
                        dungeon[i][j] += tmp;
                }
            }
        }
        
        if(dungeon[0][0] > 0)
            return 1;
        else
            return 1-dungeon[0][0];
    }
};

int main(){
    Solution solution; 
    vector<vector<int> > dungeon;
    fstream fs ("input.txt", fstream::in);
    int num_row, num_col;
    fs >> num_row;
    fs >> num_col;
    cout << num_row << ' ' << num_col << endl;
    int i, j;
    for(i=0; i<num_row; i++){
        vector<int> row;
        for(j=0; j<num_col; j++){
            int ch;
            fs >> ch;
            row.push_back(ch);
            cout << ch << ' ';
        }
        cout << endl;
        dungeon.push_back(row);
    }
    fs.close();
    
    cout << solution.calculateMinimumHP(dungeon) << endl;
}
