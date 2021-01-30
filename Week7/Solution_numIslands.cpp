class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,int cow,int col) {
        queue<vector<int>> curQue;
        curQue.emplace(vector<int>{i,j});
        while(!curQue.empty()) {
            auto curNode = curQue.front();
            curQue.pop();
            int m=curNode[0],n=curNode[1];
            if(m-1>=0 && grid[m-1][n] == '1') {
                grid[m-1][n] = '0';
                curQue.emplace(vector<int>{m-1,n});
            }
            if(m+1<cow && grid[m+1][n] == '1') {
                grid[m+1][n] = '0';
                curQue.emplace(vector<int>{m+1,n});
            }
            if(n-1>=0 && grid[m][n-1] == '1') {
                grid[m][n-1] = '0';
                curQue.emplace(vector<int>{m,n-1});
            }
            if(n+1<col && grid[m][n+1] == '1') {
                grid[m][n+1] = '0';
                curQue.emplace(vector<int>{m,n+1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0,cow=grid.size(),col=grid[0].size();
        for(int i=0;i<cow;++i) {
            for(int j=0;j<col;++j) {
                if('1' == grid[i][j]) {
                    grid[i][j] = '0';
                    bfs(grid,i,j,cow,col);
                    ++count;
                }
            }
        }
        return count;
    }
};
