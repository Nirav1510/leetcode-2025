// https://leetcode.com/problems/single-number-ii/

int singleNumber(vector<int>& nums) {
    int ans = 0, n=nums.size();

    for(int bitIdx=0; bitIdx<32; bitIdx++){
        int count = 0;

        for(int i=0;i<n;i++){
            if(nums[i] & (1 << bitIdx)){
                count++;
            }
        }

        if(count % 3 == 1){
            ans = ans | (1 << bitIdx);
        }
    }

    return ans;
}