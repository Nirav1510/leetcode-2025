// https://leetcode.com/problems/longest-consecutive-sequence/description/

int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> s(nums.begin(),nums.end());

    for(int n : nums){
        if(!s.count(n-1)){
            int count = 1;
            int currNum = n;

            while(s.count(currNum + 1)){
                currNum++;
                count++;
            }
            ans=max(ans,count);
        }
    }

    return ans;
}