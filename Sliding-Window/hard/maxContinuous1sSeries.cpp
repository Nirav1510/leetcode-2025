// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

vector<int> maxone(vector<int> &nums, int k) {
    int n = nums.size();
    int i = 0, j = 0, count = 0;
    int maxLength = 0, maxStart = 0;
    vector<int> ans;
    
    while(j<n){
        if(nums[j] == 0){
            count++;
        }

        while(count > k){
            if(nums[i] == 0){
                count--;
            }
            i++;
        }

        if (j - i + 1 > maxLength){
            maxStart = i;
            maxLength = j-i+1;
        }
        j++;
    }
    
    for (int idx = maxStart; idx < maxStart + maxLength; ++idx) {
        ans.push_back(idx);
    }

    return ans;
}
