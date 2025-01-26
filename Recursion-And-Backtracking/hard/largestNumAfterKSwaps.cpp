// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

#include <bits/stdc++.h>
using namespace std;

void solve(int start, string &ip, string &ans, int k) {
    if (k == 0 || start == ip.size()) {
        return;
    }

    // Find the maximum digit from the current position onwards
    char maxChar = *max_element(ip.begin() + start, ip.end());

    // If the current digit is already the largest, no swaps are needed
    if (ip[start] != maxChar) {
        k--;
    }

    // Iterate through the string and swap the current digit with the largest digit
    for (int i = start; i < ip.size(); i++) {
        if (ip[i] == maxChar) {
            // Swap to bring the largest character to the current position
            swap(ip[start], ip[i]);

            // Update the maximum number found so far
            if (ip > ans) {
                ans = ip;
            }

            // Recur for the next position
            solve(start + 1, ip, ans, k);

            // Backtrack
            swap(ip[start], ip[i]);
        }
    }
}

string findMaximumNum(string &s, int k) {
    string ans = s;
    solve(0, s, ans, k);
    return ans;
}

int main() {
    string s = "129814999";
    int k = 4;
    cout << "Maximum number: " << findMaximumNum(s, k) << endl;
    return 0;
}
