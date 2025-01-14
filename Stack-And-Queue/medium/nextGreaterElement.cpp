// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    
    for(int i=n-1;i>=0;i--){
        
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        
        if(!s.empty() && s.top() > arr[i]){
            ans[i] = s.top();
        }
        
        s.push(arr[i]);
    }
    return ans;
}