// https://leetcode.com/problems/subarray-sum-equals-k/


int subArraySumBruteForce(vector<int>& a, int k) {
    int n=a.size(), ans = 0;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum == k){
                ans++;
            }
        }
    }

    return ans;
}

// using hashmap
int subArraySum(vector<int>& a, int k) {
    int n=a.size(), ans = 0, sum = 0;
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        sum+=a[i];

        if(sum == k){
            ans++;
        }

        int rem = sum - k;
        if(mp.contains(rem)){
            ans = ans + mp[rem];
        }

        mp[sum]++;
    }

    return ans;
}