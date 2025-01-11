// https://leetcode.com/problems/binary-subarrays-with-sum/

int numSubArraysWithSum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int ans = 0, sum = 0;    
    mp[0] = 1;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        
        if(mp.find(sum - k) != mp.end()) {
            ans += mp[sum - k];
        }

        mp[sum]++;
    }
    
    return ans;
}