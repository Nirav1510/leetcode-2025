// https://leetcode.com/problems/01-matrix

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 0 && !vis[i][j]){
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }else{
                vis[i][j] = false;
            }
        }
    }
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    while(!q.empty()){
        auto [row, col] = q.front().first;
        int distance = q.front().second;
        q.pop();
        dist[row][col] = distance;
        
        for(int i=0;i<4;i++){
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            
            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol]){
                q.push({{nRow, nCol}, distance+1});
                vis[nRow][nCol] = true;
            }
        }
    }
    
    return dist;
}