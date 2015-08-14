#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

class Solution {
private:
    int n_row, n_col;

public:
    void solve(vector<vector<char> >& board) {
        int i, j;
        n_row = board.size();
        if(n_row <= 1)
            return ;

        n_col = board[0].size();
        if(n_col <= 1)
            return ;

        // 找到所有在边界上的O
        queue<int> edge; // 存放其位置
        // 初始化状态
        for(i=0; i<n_row; i++){
            for(j=0; j<n_col; j++){
                if((i==0 || j==0 || i==n_row-1 || j==n_col-1) && board[i][j] == 'O'){
                    int idx = i * n_col + j;
                    edge.push(idx);
                }
            }
        }

        vector<int> visited(n_row * n_col, 0);
        // 将所有跟边界O连接的O替换为S
        while(! edge.empty()){
            int idx = edge.front(); edge.pop();
            int i = idx / n_col;
            int j = idx % n_col;

            board[i][j] = 'S';
            visited[idx] = 1;
            if(j-1 >= 0 && board[i][j-1]=='O' && visited[idx - 1] == 0){
                edge.push(idx - 1);
            }
            // 右边
            if(j+1 < n_col && board[i][j+1]=='O' && visited[idx + 1] == 0){
                edge.push(idx + 1);
            }
            //上面
            if(i-1 >= 0 && board[i-1][j] == 'O' && visited[idx - n_col] == 0){
                edge.push(idx - n_col);
            }
            if(i+1 < n_row && board[i+1][j] == 'O' && visited[idx + n_col] == 0){
                edge.push(idx + n_col);
            }
        }

        for(i=0; i<n_row; i++){
            for(j=0; j<n_col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for(i=0; i<n_row; i++){
            for(j=0; j<n_col; j++){
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};

void print_board(vector<vector<char> > board){
    int n_row, n_col;
    n_row = board.size();
    n_col = board[0].size();
    int i, j;
    for(i=0; i<n_row; i++){
        for(j=0; j<n_col; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    Solution solution;
    fstream f("input.txt", fstream::in);
    int n_row, n_col;
    f >> n_row >> n_col;
    vector<vector<char> > board;
    int i, j;
    char ch;
    for(i=0; i<n_row; i++){
        vector<char> tmp;
        for(j=0; j<n_col; j++){
            f >> ch;
            tmp.push_back(ch);
        }
        board.push_back(tmp);
    }

    print_board(board);

    solution.solve(board);

    cout << "After flipping..." << endl;
    print_board(board);

}
