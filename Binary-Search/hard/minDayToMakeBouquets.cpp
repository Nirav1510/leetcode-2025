// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

bool isPossible(vector<int> &v, int m, int k, int day){
    int adjCount = 0, total = 0;

    for(int n : v){
        if(n <= day){
            adjCount++;
            if(adjCount == k){
                total++;
                adjCount = 0;
            }
        }else {
            adjCount = 0;
        }

        if (total >= m) {
            return true;
        }
    }

    return total >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size(); 
    if (val > n) return -1;

    int low = INT_MAX, high = INT_MIN;

    for(int i : bloomDay){
        low = min(low, i);
        high = max(high, i);
    }

    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(isPossible(bloomDay, m, k, mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}