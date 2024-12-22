// https://leetcode.com/problems/majority-element-ii/

vector<int> majorityElement(vector<int>& nums) {
    int el1 = INT_MIN, el2 = INT_MIN, c1 = 0, c2 =0;

    for (int n : nums) {
        if (n == el1) {
            c1++;
        } else if (n == el2) {
            c2++;
        } else if (c1 == 0) {
            el1 = n;
            c1 = 1;
        } else if (c2 == 0) {
            el2 = n;
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }

    int mini = (nums.size()/3);
    c1 = 0, c2 =0;
    vector<int> ans;

    for(int n:nums){
        if(el1 == n) c1++;
        if(el2 == n) c2++;
    }

    if(c1 > mini) ans.push_back(el1);
    if(c2 > mini) ans.push_back(el2);

    return ans;
}