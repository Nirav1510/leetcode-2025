// https://leetcode.com/problems/number-of-1-bits/

int hammingWeight(int n) {
    int ans = 0;

    while(n){
        ans += n & 1;
        n = n >> 1;
    }
    return ans;
}