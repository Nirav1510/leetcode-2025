// https://leetcode.com/problems/subarrays-with-k-different-integers/

int solve(vector<int> &nums, int k){
    unordered_map<int,int> mp;
    int ans = 0, i = 0, j = 0, n = nums.size();

    while(j<n){
        mp[nums[j]]++;

        while(mp.size() > k){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
            i++;
        }

        ans += (j-i+1);
        j++;
    }

    return ans;
}

int subArraysWithKDistinct(vector<int>& nums, int k) {
    return solve(nums, k) - solve(nums, k-1);
}