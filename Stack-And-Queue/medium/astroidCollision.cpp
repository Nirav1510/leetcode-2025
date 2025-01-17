// https://leetcode.com/problems/asteroid-collision/

vector<int> asteroidCollision(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;

    for(int i=0;i<n;i++){
        bool canWePush = true;

        while(!s.empty() && arr[i] < 0 && s.top() > 0) {
            if(abs(arr[i]) > s.top()) {
                s.pop(); 
            } else{
                if(abs(arr[i]) == s.top()){
                    s.pop();
                }
                canWePush = false; 
                break;
            }
        }
        
        // If no collision occurred, add the current asteroid to the stack
        if(canWePush) {
            s.push(arr[i]);
        }
    }

    vector<int> ans(s.size());
    int index = s.size() - 1;
    while(!s.empty()) {
        ans[index] = s.top();
        index--;
        s.pop();
    }
    return ans;
}