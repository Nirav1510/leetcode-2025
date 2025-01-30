// https://leetcode.com/problems/top-k-frequent-elements/

// Time Complexity: O(nlogk), Space Complexity: O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> mp;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    for(int n : nums){
        mp[n]++;
    }

    for(auto &it : mp){
        minHeap.push({it.second, it.first});

        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    while(!minHeap.empty()){
        int num = minHeap.top().second;
        minHeap.pop();
        ans.push_back(num);
    }
    return ans;
}

// bucket sort technique
// Time Complexity: O(n), Space Complexity: O(n) 
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    int n = nums.size();
    vector<vector<int>> bucket(n + 1); // Frequency can be at most `n`
    
    for (auto& [num, freq] : freqMap) {
        bucket[freq].push_back(num);
    }

    vector<int> ans;
    for (int i = n; i >= 0 && ans.size() < k; --i) {
        for (int num : bucket[i]) {
            ans.push_back(num);
            if (ans.size() == k) return ans;
        }
    }
    
    return ans;
}
