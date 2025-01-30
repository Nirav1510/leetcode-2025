// https://leetcode.com/problems/top-k-frequent-elements/

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