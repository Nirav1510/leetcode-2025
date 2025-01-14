// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
    int revNum = 0;

    while (n != 0) {
        int ld = n % 10;
        if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && ld > INT_MAX % 10)) {
            return 0; 
        }
        if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && ld < INT_MIN % 10)) {
            return 0; 
        }

        revNum = (revNum * 10) + ld;
        n /= 10;
    }

    return revNum;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n) << endl;
    return 0;
}