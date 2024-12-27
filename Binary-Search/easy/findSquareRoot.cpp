// https://www.geeksforgeeks.org/problems/square-root/0

int floorSqrt(int n) {
    if(n <= 3) return 1;
    int low = 1, high = n, ans = 1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if(mid == n/mid){
            return mid;
        }else if(mid > n/mid){
            high=mid-1;
        }else{
            ans = mid;
            low=mid+1;
        }
    }
    
    return ans;
}