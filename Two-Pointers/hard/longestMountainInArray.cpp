// https://leetcode.com/problems/longest-mountain-in-array/

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if(n < 3) return 0;

    int ans = 0;

    for(int i=1;i<n-1;i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            int left = i-1, right = i+1;

            while(left > 0 && arr[left-1] < arr[left]){
                left--;
            }

            while(right < n-1 && arr[right+1] < arr[right]){
                right++;
            }

            ans = max(ans, right-left+1);
        }
    }
    return ans;
}