int subArraysWithGivenXor(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    unordered_map<int,int> mp;
    int xr = 0;
    mp[xr]++;
    
    for(int i=0;i<n;i++){
        xr ^=a[i];
        
        int x = xr^k;
        
        if(mp.find(x) != mp.end()){
            ans+=mp[x];
        }
        
        mp[xr]++;
    }
    
    return ans;
}