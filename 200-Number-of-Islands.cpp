#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <fstream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int num_row = grid.size(); // 行数
        if(num_row == 0)
            return 0;
            
        int num_col = grid[0].size(); // 列数
        // 在grid四周添加'0'
        vector<char> wall;
        int i, j;
        for(i=0; i<num_col+2; i++)
            wall.push_back('0');
        grid.insert(grid.begin(), wall); // 上方的wall
        grid.push_back(wall); // 下方的wall
        // 添加左右的wall
        for(i=1; i<=num_row; i++){
            grid[i].insert(grid[i].begin(), '0'); // 添加左边的边界
            grid[i].push_back('0'); // 添加右边的边界
        }
        
        //print_grid(grid);
        
        int num_islands = 0;
        // 当前的行数和列数
        num_row += 2;
        num_col += 2;
        for(i=1; i<num_row-1; i++){
            for(j=1; j<num_col-1; j++){
                if(grid[i][j] == '1'){
                    num_islands ++;
                    dfs_visit(i, j, grid);
                }
            }
        }
        
        return num_islands;
    }
    
    void dfs_visit(int i, int j, vector<vector<char> >& grid){
        if(grid[i-1][j] == '1'){
            grid[i-1][j] = '0';
            dfs_visit(i-1, j, grid);
        }
        
        if(grid[i+1][j] == '1'){
            grid[i+1][j] = '0';
            dfs_visit(i+1, j, grid);
        }
        
        if(grid[i][j-1] == '1'){
            grid[i][j-1] = '0';
            dfs_visit(i, j-1, grid);
        }
        
        if(grid[i][j+1] == '1'){
            grid[i][j+1] = '0';
            dfs_visit(i, j+1, grid);
        }
        
    }
};

int main(){
    Solution solution; 
    vector<vector<char> > grid;
    fstream fs ("input.txt", fstream::in);
    int num_row, num_col;
    fs >> num_row;
    fs >> num_col;
    cout << num_row << ' ' << num_col << endl;
    int i, j;
    for(i=0; i<num_row; i++){
        vector<char> row;
        for(j=0; j<num_col; j++){
            int ch;
            fs >> ch;
            if(ch == 1)
                row.push_back('1');
            else
                row.push_back('0');
                
            cout << ch << ' ';
        }
        cout << endl;
        grid.push_back(row);
    }
    fs.close();
    
    cout << solution.numIslands(grid) << endl;
}
