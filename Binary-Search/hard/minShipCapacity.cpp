// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

bool isPossible(vector<int>& weights, int maxDays, int shipWeight) {
    int totalDays = 1, sum = 0;

    for (int weight : weights) {
        if (weight > shipWeight) {
            return false;
        }

        if (sum + weight > shipWeight) {
            totalDays++; 
            sum = weight; 
        } else {
            sum += weight;
        }

        if (totalDays > maxDays) {
            return false;
        }
    }

    return true; 
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0); 
    int ans = high;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(isPossible(weights, days, mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    
    return ans;
}