// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

vector<int> leaders(vector<int>& arr) {
    vector<int> ans;
    int n=arr.size();
    
    ans.push_back(arr[n-1]);
    
    if(n==1) return ans;
    
    int currMax = arr[n-1];
    
    for(int i=n-2;i>=0;i--){
        if(arr[i] >= currMax){
            currMax = arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}