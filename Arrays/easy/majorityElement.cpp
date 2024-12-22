// https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& nums) {
    int ans, count = 0;

    for(int n : nums){
        if(count == 0){
            ans = n;
        }

        if(ans == n){
            count++;
        }else{
            count--;
        }
    }

    return ans;
}