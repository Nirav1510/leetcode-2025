// https://leetcode.com/problems/number-of-islands

void bfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>>& grid){
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;

    visited[r][c] = true;
    q.push({r, c});

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nRow = row + drow[i];
            int nCol = col + dcol[i];

            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == '1'){
                visited[nRow][nCol] = true;
                q.push({nRow, nCol});
            }
        }
          
    }
}

void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>>& grid){
    int n = grid.size(), m = grid[0].size();
    visited[r][c] = true;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nRow = r + drow[i];
        int nCol = c + dcol[i];

        if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == '1'){
            dfs(nRow, nCol, visited, grid);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islands = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                islands++;
                bfs(i, j, visited, grid);
            }
        }
    }

    return islands;
}