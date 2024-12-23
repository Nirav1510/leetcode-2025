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

// using hashmap
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int sum = 0, ans = 0, n = arr.size();
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
        
        if(sum == k){
            ans = max(ans, i+1);
        }
        
        int rem = sum - k;
        if(mp.find(rem) != mp.end()){
            int length = i - mp[rem];
            ans = max(ans, length);
        }
        
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
        
    }
    
    return ans;
}