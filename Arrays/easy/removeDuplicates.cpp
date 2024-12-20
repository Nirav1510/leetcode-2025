// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(vector<int>& nums) {
    int n=nums.size(), start = 0;

    for(int end=1;end<n;end++){
        if(nums[start] != nums[end]){
            start++;
            nums[start] = nums[end];
        }
    }
    return start+1;
}