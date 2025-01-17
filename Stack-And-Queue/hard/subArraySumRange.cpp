// https://leetcode.com/problems/sum-of-subarray-ranges/

vector<int> nextSmallerToLeft(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=0;i<n;i++){

        while(!s.empty() && arr[s.top()] > arr[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = i + 1;
        }else {
            ans[i] = i - s.top();
        }

        s.push(i);
    }
    return ans;
}

vector<int> nextGreaterToLeft(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=0;i<n;i++){

        while(!s.empty() && arr[s.top()] < arr[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = i+1;
        }else {
            ans[i] = i-s.top();
        }

        s.push(i);
    }
    return ans;
}

vector<int> nextSmallerToRight(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){

        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = n - i;
        }else{
            ans[i] = s.top() - i;
        }

        s.push(i);
    }
    return ans;
}

vector<int> nextGreaterToRight(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){

        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = n-i;
        }else{
            ans[i] = s.top()-i;
        }

        s.push(i);
    }
    return ans;
}

long long sumSubArrayMax(vector<int>& arr) {
    long long total = 0;
    int n = arr.size();
    vector<int> ngeLeft = nextGreaterToLeft(arr, n);
    vector<int> ngeRight = nextGreaterToRight(arr, n);

    for(int i = 0; i < n; i++){
        total += (long long)(arr[i]) * (long long)(ngeLeft[i]) * (long long)(ngeRight[i]);
    }

    return total;
}

long long sumSubArrayMin(vector<int>& arr) {
    long long total = 0;
    int n = arr.size();
    vector<int> nseLeft = nextSmallerToLeft(arr, n);
    vector<int> nseRight = nextSmallerToRight(arr, n);

    for(int i = 0; i < n; i++){
        total += (long long)(arr[i]) * (long long)(nseLeft[i]) * (long long)(nseRight[i]);
    }

    return total;
}

long long subArrayRanges(vector<int>& nums) {
    return sumSubArrayMax(nums) - sumSubArrayMin(nums);
}