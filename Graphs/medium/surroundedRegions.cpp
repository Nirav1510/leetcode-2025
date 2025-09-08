// https://leetcode.com/problems/surrounded-regions

void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>>& mat){
    int n = mat.size(), m = mat[0].size();
    vis[r][c] = true;
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    
    for(int i=0;i<4;i++){
        int nRow = r + dx[i];
        int nCol = c + dy[i];
        
        if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 'O'){
            dfs(nRow, nCol, vis, mat);
        }
    }
}

void bfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>>& mat) {
    int n = mat.size(), m = mat[0].size();
    queue<pair<int,int>> q;
    q.push({r, c});
    vis[r][c] = true;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nRow = x + dx[i];
            int nCol = y + dy[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && mat[nRow][nCol] == 'O') {
                vis[nRow][nCol] = true;
                q.push({nRow, nCol});
            }
        }
    }
}

void surroundedRegions(vector<vector<char>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    // first and last row
    for(int j=0;j<m;j++){
        if(!vis[0][j] && mat[0][j] == 'O'){
            dfs(0, j, vis, mat);
            // bfs(0, j, vis, mat);
        }
        
        if(!vis[n-1][j] && mat[n-1][j] == 'O'){
            dfs(n-1, j, vis, mat);
            // bfs(n-1, j, vis, mat);
        }
    }
    
    // first and last column
    for(int i=0;i<n;i++){
        if(!vis[i][0] && mat[i][0] == 'O'){
            dfs(i, 0, vis, mat);
            // bfs(i, 0, vis, mat);
        }
        
        if(!vis[i][m-1] && mat[i][m-1] == 'O'){
            dfs(i, m-1, vis, mat);
            // bfs(i, m-1, vis, mat);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }
}