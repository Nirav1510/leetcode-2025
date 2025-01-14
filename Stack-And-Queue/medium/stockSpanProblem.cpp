// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 1); // Initialize all spans as 1
    stack<int> s;          // Stack to store indices of elements

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while they are less than or equal to the current element
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // If the stack is empty, the span is i + 1 (all elements up to this point)
        if (s.empty()) {
            ans[i] = i + 1;
        } else {
            // Else, span is the difference between the current index and the index of the last greater element
            ans[i] = i - s.top();
        }

        // Push the current index onto the stack
        s.push(i);
    }

    return ans;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(prices);

    for (int span : result) {
        cout << span << " ";
    }

    return 0;
}