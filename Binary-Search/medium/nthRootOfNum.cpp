long long int myPow(int x, int n) {
    long long int ans = 1;

    while(n>0){
        if(n%2 == 1){
            ans *= x;
            n--;
        }else{
            x *= x;
            n /= 2;
        }
    }

    return ans;
}

int nthRoot(int n, int m) {
    int low = 1, high = m;
    long long int k = m;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        long long int value = myPow(mid, n);
        
        if(value == k){
            return mid;
        }else if(value > k){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}