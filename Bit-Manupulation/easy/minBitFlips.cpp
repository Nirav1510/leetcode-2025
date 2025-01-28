// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

int countBits(int n){
    int ans = 0;
    
    while(n){
        n = n&(n-1);
        ans++;
    }
    return ans;
}

int minBitFlips(int start, int goal) {
    return countBits(start^goal);
}