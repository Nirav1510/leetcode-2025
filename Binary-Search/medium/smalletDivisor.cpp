// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

bool isPossible(vector<int> &nums, int d, int t){
    int sum = 0;

    for(int n : nums){
        sum += (n+d-1)/d;
        if(sum > t){
            return false;
        }
    }
    return true;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = INT_MIN;

    for(int n : nums){
        high = max(high, n);
    }

    int ans = high;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(isPossible(nums, mid, threshold)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    
    return ans;
}