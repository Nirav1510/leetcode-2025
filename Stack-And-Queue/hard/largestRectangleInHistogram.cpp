// https://leetcode.com/problems/largest-rectangle-in-histogram/

vector<int> nextSmallerToLeft(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=0;i<n;i++){

        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        }else {
            ans[i] = s.top();
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
            ans[i] = n;
        }else{
            ans[i] = s.top();
        }

        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int ans = 0, n = heights.size();
    vector<int> nseLeft = nextSmallerToLeft(heights, n);
    vector<int> nseRight = nextSmallerToRight(heights, n);

    for(int i=0;i<n;i++){
        int width = nseRight[i] - nseLeft[i] - 1;
        int area = heights[i] * width;
        ans = max(ans, area);
    }
    return ans;
}