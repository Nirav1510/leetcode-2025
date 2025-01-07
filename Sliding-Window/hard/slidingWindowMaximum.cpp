// https://leetcode.com/problems/sliding-window-maximum/

vector<int> slidingMaximum(const vector<int> &arr, int k) {
    int n = arr.size();
    if(k > n) return {*max_element(arr.begin(), arr.end())};
    deque<int> dq;
    vector<int> ans;
    int i = 0, j = 0;
    
    while(j<n){
        while(!dq.empty() && dq.back() < arr[j]){
            dq.pop_back();
        }
        dq.push_back(arr[j]);
        
        if(j-i+1 == k){
            ans.push_back(dq.front());
            
            if(dq.front() == arr[i]){
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
}
