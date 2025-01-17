// https://leetcode.com/problems/trapping-rain-water/

int trap(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n-1;
    int maxL = 0, maxR = 0, total = 0;

    while(left<=right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= maxL){
                maxL = arr[left];
            }else{
                total += maxL - arr[left];
            }
            left++;
        }else{
            if(arr[right] >= maxR){
                maxR = arr[right];
            }else{
                total += maxR - arr[right];
            }
            right--;
        }
    }
    return total;
}

int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];

  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }

  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }

  return waterTrapped;
}