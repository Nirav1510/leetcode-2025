// https://leetcode.com/problems/sort-characters-by-frequency/

string frequencySort(string s) {
    string ans;
    unordered_map<int, int> mp;
    priority_queue<pair<int,char>> maxHeap;

    for(char c : s){
        mp[c]++;
    }

    for(auto &it : mp){
        maxHeap.push({it.second, it.first});
    }

    while(!maxHeap.empty()){
        int freq = maxHeap.top().first;
        char c = maxHeap.top().second;
        maxHeap.pop();

        while(freq){
            ans.push_back(c);
            freq--;
        }
    }
    return ans;
}