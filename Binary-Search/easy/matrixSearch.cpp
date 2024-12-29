// https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m-1;
    
    while(i>=0 && i<n && j>=0 && j<m){
        if(mat[i][j] == x){
            return true;
        }else if(mat[i][j] > x){
            j--;
        }else{
            i++;
        }
    }
    return false;
}