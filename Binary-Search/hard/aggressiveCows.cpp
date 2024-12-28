// https://www.geeksforgeeks.org/problems/aggressive-cows/1

bool isPossibleToPlace(vector<int> &stalls, int dist, int k){
    int cowCount = 1, last = stalls[0];
    
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - last >= dist){
            cowCount++;
            last = stalls[i];
        }
        
        if(cowCount >= k){
            return true;
        }
    }
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    
    int low = 1, high = stalls[n-1] - stalls[0];
    int ans = 0;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if(isPossibleToPlace(stalls, mid, k)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return ans;
}