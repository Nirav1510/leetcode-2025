int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    
    int freshCount = 0;
    int maxTime = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }else{
                vis[i][j] = 0;
            }

            if(grid[i][j] == 1) freshCount++;
        }
    }

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    int count = 0;

    while(!q.empty()){
        auto [row, col] = q.front().first;
        int time = q.front().second;
        q.pop();

        maxTime = max(time, maxTime);
        for(int i=0;i<4;i++){
            int nRow = row + drow[i];
            int nCol = col + dcol[i];

            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                vis[nRow][nCol] = 2;
                q.push({{nRow, nCol}, time+1});
                count++;
            }
        }
    }

    return count == freshCount ? maxTime : -1;
}