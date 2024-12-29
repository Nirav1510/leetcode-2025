// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

int lowerBound(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int ans = n;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= k) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    
    int maxCount = 0, ansRow = -1;
    
    for(int i=0;i<n;i++){
        int countOne = m - lowerBound(mat[i], m , 1);
        
        if(countOne > maxCount){
            maxCount = countOne;
            ansRow = i;
        }
    }
    return ansRow;
}