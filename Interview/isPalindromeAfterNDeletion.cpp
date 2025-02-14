// Given a string s, return true if the s can be palindrome after deleting at most n character from it.

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;

bool canBePalindrome(string s, int left, int right, int n){
    if(n < 0) return false;
    if(left >= right) return true;

    string key = to_string(left) + "," + to_string(right) + "," + to_string(n);

    if(dp.find(key) != dp.end()){
        return dp[key];
    }

    if(s[left] == s[right]){
        return dp[key] = canBePalindrome(s, left + 1, right - 1, n);
    }

    return dp[key] = canBePalindrome(s, left + 1, right, n - 1) || canBePalindrome(s, left, right - 1, n - 1);
}

bool isPalindromeAfterDeletion(string s, int n){
    return canBePalindrome(s, 0, s.length() - 1, n);
}

// ------- using Longest Palindrome Subsequence -------
int longestPalindromicSubsequence(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Single characters are palindromes of length 1
    for (int i = 0; i < n; i++) dp[i][i] = 1;

    // Fill DP table for substrings of length 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1]; // LPS length
}

bool checkCanBePalindrome(string s, int n) {
    int lpsLength = longestPalindromicSubsequence(s);
    return (s.length() - lpsLength) <= n;
}


int main(){
    string s = "abcdaedba";
    int n = 2;

    cout << isPalindromeAfterDeletion(s,n) ? "true" : "false" << endl;

    cout << checkCanBePalindrome(s,n) ? "true" : "false";

    return 0;
}