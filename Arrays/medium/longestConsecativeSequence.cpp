// https://leetcode.com/problems/longest-consecutive-sequence/description/

int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> s(nums.begin(),nums.end());

    for(int n : nums){
        // check if it is the start of a sequence
        if(!s.count(n-1)){
            int count = 1;
            int currNum = n;

            // count the length of the sequence
            while(s.count(currNum + 1)){
                currNum++;
                count++;
            }
            ans=max(ans,count);
        }
    }

    return ans;
}

// brute force
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int ans = 1;
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            // skip duplicates
            continue;
        }
        if (nums[i] == nums[i - 1] + 1) {
            count++;
        } else {
            ans = max(ans, count);
            count = 1; // reset for new sequence
        }
    }

    ans = max(ans, count); // handle last sequence
    return ans;
}
