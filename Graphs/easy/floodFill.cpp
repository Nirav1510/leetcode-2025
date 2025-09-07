// https://leetcode.com/problems/flood-fill

void dfs(int r, int c, vector<vector<int>> &ans, vector<vector<int>> &mat, int newColor, int initColor){
    int n = mat.size(), m = mat[0].size();
    ans[r][c] = newColor;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nRow = r + drow[i];
        int nCol = c + dcol[i];

        if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && mat[nRow][nCol] == initColor && ans[nRow][nCol] != newColor){
            dfs(nRow, nCol, ans, mat, newColor, initColor);
        }
    }
}

void bfs(int r, int c, vector<vector<int>> &ans, vector<vector<int>> &mat, int newColor, int initColor){
    int n = mat.size(), m = mat[0].size();
    queue<pair<int, int>> q;
    ans[r][c] = newColor;
    q.push({r, c});

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nRow = row + drow[i];
            int nCol = col + dcol[i];

            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && mat[nRow][nCol] == initColor && ans[nRow][nCol] != newColor){
                ans[nRow][nCol] = newColor;
                q.push({nRow, nCol});
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
    int n = mat.size(), m = mat[0].size();
    int initColor = mat[sr][sc];
    vector<vector<int>> ans = mat;
    vector<vector<bool>> visited(n, vector<bool>(m ,false));

    dfs(sr, sc, ans, mat, color, initColor);
    return ans;
}