// https://leetcode.com/problems/search-a-2d-matrix-ii/

bool searchMatrix(vector<vector<int>>& mat, int key) {
    int n = mat.size(), m = mat[0].size();

    int row = 0, col = m-1;

    while(row>=0 && row<n && col>=0 && col<m){
        if(mat[row][col] == key){
            return true;
        }else if(mat[row][col] > key){
            col--;
        }else{
            row++;
        }
    }
    return false;
}