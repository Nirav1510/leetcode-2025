// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    // write code here
    vector<int> ans;
    queue<int> q; // to store -ve numbers
    
    int n = arr.size(), i = 0, j = 0;
    while(j<n){
        if(arr[j]<0){
            q.push(arr[j]);
        }
        
        if(j-i+1 == k){
            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(q.front());
                
                if(arr[i] == q.front()){
                    q.pop();
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}