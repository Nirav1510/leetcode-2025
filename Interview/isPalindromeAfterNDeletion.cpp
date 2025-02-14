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

int main(){
    string s = "abcba";
    int n = 2;

    cout << isPalindromeAfterDeletion(s,n) ? "true" : "false";

    return 0;
}