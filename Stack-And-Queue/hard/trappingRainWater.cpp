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