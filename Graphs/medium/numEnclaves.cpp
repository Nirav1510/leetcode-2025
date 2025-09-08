// https://leetcode.com/problems/number-of-enclaves

void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vis[r][c] = true;
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    
    for(int i=0;i<4;i++){
        int nRow = r + dx[i];
        int nCol = c + dy[i];
        
        if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 1){
            dfs(nRow, nCol, vis, mat);
        }
    }
}

int numEnclaves(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;

    // first and last row
    for(int j=0;j<m;j++){
        if(!vis[0][j] && mat[0][j] == 1){
            dfs(0, j, vis, mat);
        }
        
        if(!vis[n-1][j] && mat[n-1][j] == 1){
            dfs(n-1, j, vis, mat);
        }
    }
    
    // first and last column
    for(int i=0;i<n;i++){
        if(!vis[i][0] && mat[i][0] == 1){
            dfs(i, 0, vis, mat);
        }
        
        if(!vis[i][m-1] && mat[i][m-1] == 1){
            dfs(i, m-1, vis, mat);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j] == 1){
                ans++;
            }
        }
    }

    return ans;
}

// BFS approach
int numEnclavesBFS(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i == 0 || j == 0 || i == n-1 || j == m-1) && !vis[i][j] && mat[i][j] == 1){
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    
    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            
            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 1){
                q.push({nRow, nCol});
                vis[nRow][nCol] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j] == 1){
                ans++;
            }
        }
    }

    return ans;
}