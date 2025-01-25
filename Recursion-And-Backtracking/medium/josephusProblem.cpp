// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

void solve(vector<int> &nums, int idx, int &ans, int k){
    if(nums.size() == 1){
        ans = nums[0];
        return;
    }
    
    idx = (idx + k) % nums.size();
    nums.erase(nums.begin() + idx);
    solve(nums, idx, ans, k);
}

int findTheWinner(int n, int k) {
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++){
        nums[i] = i+1;
    }
    
    int ans = -1;
    int idx = 0;
    k = k-1;
    
    solve(nums, idx, ans, k);
    
    return ans;
}