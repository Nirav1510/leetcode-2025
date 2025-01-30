// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include <bits/stdc++.h>
using namespace std;

// Type alias for priority queue elements (value, (row index, column index))
typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
    vector<int> ans;

    // Min heap (priority queue) to store the smallest elements
    // It stores tuples of (value, (row index, column index))
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    // Step 1: Insert the first element of each array into the heap
    for (int i = 0; i < arr.size(); i++) {
        pq.push({arr[i][0], {i, 0}});  // Push (first element, (row index, column index))
    }

    // Step 2: Extract min element and insert next element from the same array
    while (!pq.empty()) {
        ppi curr = pq.top(); // Get the smallest element
        pq.pop(); // Remove it from the heap

        int row = curr.second.first;  // Array index
        int col = curr.second.second; // Position in the array

        ans.push_back(curr.first); // Add smallest element to the result

        // Step 3: If there is another element in the same row, push it to the heap
        if (col + 1 < arr[row].size()) {
            pq.push({arr[row][col + 1], {row, col + 1}});
        }
    }

    return ans; // Return the merged sorted array
}

// Test function
int main() {
    vector<vector<int>> arr = { { 2, 6, 12 }, { 1, 9 }, { 23, 34 } };
    vector<int> result = mergeKArrays(arr, arr.size());

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
