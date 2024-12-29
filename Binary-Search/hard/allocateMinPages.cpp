#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int totalStudents, int maxPages) {
    int student = 1, pages = 0;

    for (int a : arr) {
        pages += a;
        if (pages > maxPages) {
            student++;
            pages = a;
        }

        if (student > totalStudents) {
            return false;
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int k) {
    if (n < k) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int k = 2;
    cout << "Minimum number of pages: " << findPages(arr, n, k) << endl;
    return 0;
}
