// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

int maxScore(vector<int>& cardPoints, int k) {
    int ans = 0, n = cardPoints.size();
    int i = 0, j = 0, sum = 0;
    int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

    if(k == n) return total;

    while(j<n){
        sum += cardPoints[j];

        if(j-i+1 > n-k){
            sum -= cardPoints[i];
            i++;
        }

        if(j-i+1 == n-k){
            ans = max(ans, total-sum);
        }
        j++;
    }
    return ans;
}