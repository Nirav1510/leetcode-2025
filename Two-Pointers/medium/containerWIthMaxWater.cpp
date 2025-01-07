// https://leetcode.com/problems/container-with-most-water/

int maxArea(vector<int>& arr) {
    int i = 0, j = arr.size()-1;
    int ans = 0;
    
    while(i<j){
        int width = j-i;
        int length = min(arr[i], arr[j]);
        
        ans = max(ans, length*width);
        
        if (arr[i] < arr[j]) {
            i++;
        } else {
            j--;
        }
    }
    return ans;
}