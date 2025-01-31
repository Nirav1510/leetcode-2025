// https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/0

long long findKthSmallest(long long nums[],long long n, long long k) {
    priority_queue<long long> maxH;

    for(long long i=0;i<n;i++){
        maxH.push(nums[i]);

        if(maxH.size() > k){
            maxH.pop();
        }
    }
    
    return maxH.top();
}

long long sumBetweenTwoKth(long long nums[], long long n, long long k1, long long k2){
    long long first = findKthSmallest(nums, n, k1);
    long long second = findKthSmallest(nums, n, k2);
    long long ans = 0;
    
    
    for(long long i=0;i<n;i++){
        if(nums[i] > first && nums[i] < second){
            ans+= nums[i];
        }
    }
    return ans;
}