// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

void solve(stack<int> &s, int mid){
    if(mid == 1){
        s.pop();
        return;
    }
    
    int temp = s.top();
    s.pop();
    solve(s, mid-1);
    s.push(temp);
}

void deleteMid(stack<int>& s) {
    int mid = s.size()/2 + 1;
    solve(s, mid);
}