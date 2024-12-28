// https://leetcode.com/problems/koko-eating-bananas/

bool isPossible(vector<int>& piles, int k, int h) {
    int totalH = 0;

    for (int i : piles) {
        totalH += (i + k - 1) / k;
        if (totalH > h) return false;
    }

    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = INT_MIN;

    for(int i : piles){
        if(i > high) high = i;
    }

    int ans = high;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (isPossible(piles, mid, h)) {
            ans = mid; 
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }

    return ans;
}