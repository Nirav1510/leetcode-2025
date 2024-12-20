// https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    int top = 0, bottom = rows-1, left = 0, right = cols-1;
    vector<int> ans;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}