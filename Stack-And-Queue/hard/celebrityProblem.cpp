// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// brute force
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> knowMe(m, 0);
    vector<int> iKnow(m, 0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        if(iKnow[i] == 0 && knowMe[i] == m-1){
            return i;
        }
    }
    return -1;
}


// optimized solution using two pointers
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    int top = 0, bottom = n-1;
    
    while(top<bottom){
        if(mat[top][bottom] == 1){
            top++;
        }else if(mat[bottom][top] == 1){
            bottom--;
        }else{
            top++;
            bottom--;
        }
    }
    
    if(top>bottom) return -1;
    
    for(int i=0;i<n;i++){
        if(top != i){
            if(mat[top][i] != 0 || mat[i][top] != 1){
                return -1;
            }
        }
    }
    
    return top;
}
