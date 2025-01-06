// https://leetcode.com/problems/3sum-closest/

int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int ans = INT_MAX / 2;

    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        int j=i+1, k = n-1;

        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            
            if (abs(target - sum) < abs(target - ans)) {
                ans = sum;
            }

            if(sum == target){
                return sum;
            }else if(sum > target){
                k--;
            }else{
                j++;
            }
        }
    }
    return ans;
}