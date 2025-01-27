// https://leetcode.com/problems/word-search/

bool check(int idx, int &n, int &m, int row, int col, string &word, vector<vector<char>>& board){
    if(idx == word.size()){
        return true;
    }

    if(row < 0 || row == n || col < 0 || col == m || word[idx] != board[row][col] || board[row][col] == '!'){
        return false;
    }

    char letter = board[row][col];
    board[row][col] = '!';

    bool top = check(idx+1, n, m, row, col-1, word, board);
    bool bottom = check(idx+1, n, m, row, col+1, word, board);
    bool left = check(idx+1, n, m, row-1, col, word, board);
    bool right = check(idx+1, n, m, row+1, col, word, board);

    board[row][col] = letter;

    return top || bottom || left || right;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    int idx = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == word[idx]){
                if(check(idx, n, m, i, j, word, board)){
                    return true;
                }
            }
        }
    }
    return false;
}