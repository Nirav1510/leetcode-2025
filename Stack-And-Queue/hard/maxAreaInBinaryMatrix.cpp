// https://leetcode.com/problems/maximal-rectangle/

vector<int> nextSmaller(vector<int>& arr, int n, bool toLeft) {
    stack<int> s;
    vector<int> ans(n);
    int start = toLeft ? 0 : n - 1;
    int end = toLeft ? n : -1;
    int step = toLeft ? 1 : -1;

    for (int i = start; i != end; i += step) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }

        if(s.empty()){
            if(toLeft){
                ans[i] = -1;
            }else{
                ans[i] = n;
            }
        }else{
            ans[i] = s.top();
        }

        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> nseLeft = nextSmaller(heights, n, true);
    vector<int> nseRight = nextSmaller(heights, n, false);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nseRight[i] - nseLeft[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& mat) {
    if (mat.empty() || mat[0].empty()) return 0;

    int n = mat.size(), m = mat[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mat[i][j] == '0'){
                heights[j] = 0;
            }else{
                heights[j] += 1;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}