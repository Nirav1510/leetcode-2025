// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

int minCost(vector<int>& nums) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int n : nums){
        minHeap.push(n);
    }
    
    while(minHeap.size() > 1){
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        
        ans += first+second;
        
        minHeap.push(first+second);
    }
    return ans;
}