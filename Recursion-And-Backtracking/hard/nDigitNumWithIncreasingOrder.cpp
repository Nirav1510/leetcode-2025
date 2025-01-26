// https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1

int getNumber(vector<int> &arr){
    int res = 0;
    for(int i=0;i<arr.size();i++){
        res = res*10 + arr[i]; 
    }
    return res;
}

void solve(int n, vector<int> &curr, vector<int> &ans){
    if(n == 0){
        int num = getNumber(curr);
        ans.push_back(num);
        return;
    }
    
    for(int i=1;i<10;i++){
        if(curr.size() == 0 || i > curr[curr.size()-1]){
            curr.push_back(i);
            solve(n-1, curr, ans);
            curr.pop_back();
        }
    }
}

vector<int> increasingNumbers(int n) {
    vector<int> ans;
    if(n == 1){
        for(int i=0;i<10;i++){
            ans.push_back(i);
        }
        return ans;
    }
    
    vector<int> curr;
    solve(n, curr, ans);
    
    return ans;
}

// ------ Another Solution ------

void solve(int n, int start, int curr, vector<int> &ans){
    if(n == 0){
        ans.push_back(curr);
        return;
    }
    
    for(int i=start;i<10;i++){
        solve(n-1, i+1, curr*10 + i, ans);
    }
}

vector<int> increasingNumbers(int n) {
    vector<int> ans;
    if(n == 1){
        for(int i=0;i<10;i++){
            ans.push_back(i);
        }
        return ans;
    }
    
    solve(n, 1, 0, ans);
    
    return ans;
}