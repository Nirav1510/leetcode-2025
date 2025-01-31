// https://leetcode.com/problems/k-closest-points-to-origin/

// Time Complexity: O((n+k)logk), Space Complexity: O(k)
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    priority_queue<pair<int, vector<int>>> maxHeap;
    int n = points.size();

    for(int i=0;i<n;i++){
        int x = points[i][0], y = points[i][1];
        int distance = x*x + y*y;

        maxHeap.push({distance, {x, y}});

        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }

    while(!maxHeap.empty()){
        vector<int> point = maxHeap.top().second;
        maxHeap.pop();
        ans.push_back(point);
    }
    
    return ans;
}