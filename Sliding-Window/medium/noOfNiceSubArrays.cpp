// https://leetcode.com/problems/count-number-of-nice-subarrays/

int solve(vector<int> &arr, int k){
    int ans = 0, count = 0, i = 0, n = arr.size();
    if(k < 0) return 0;

    for(int j=0;j<n;j++){
        if(arr[j] % 2 == 1){
            count++;
        }

        while(count > k){
            if(arr[i]%2 == 1){
                count--;
            }
            i++;
        }
        ans += (j-i+1); 
    }
    return ans;
}

int numberOfSubArrays(vector<int>& arr, int k) {
    return solve(arr, k) - solve(arr, k-1);
}