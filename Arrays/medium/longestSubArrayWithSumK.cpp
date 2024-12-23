int longestSubArrayWithSumK(vector<int> &a, long long k) {
    int ans = 0, i = 0, n = a.size();
    long long sum = 0;

    for(int j=0;j<n;j++){
        sum = sum + a[j];

        while(sum > k){
            sum = sum - a[i];
            i++;
        }

        if(sum == k){
            ans = max(ans, j-i+1);
        }
    }

    return ans;
}