void solve(vector<int> &v){
    int n = v.size();
    int temp = v[n-1];

    for(int i = n-1; i > 0; i--){
        v[i] = v[i-1];
    }
    v[0] = temp;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;

    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}