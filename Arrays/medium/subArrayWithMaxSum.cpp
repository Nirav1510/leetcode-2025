#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& arr) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    int start = 0, end = 0, tempStart = 0;
    vector<int> result;

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > currentSum + arr[i]) {
            currentSum = arr[i];
            tempStart = i; // Start a new subarray
        } else {
            currentSum += arr[i];
        }

        if(currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i; // Current end of the subarray
        }
    }

    for(int i = start; i <= end; i++) {
        result.push_back(arr[i]);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(arr);
    return 0;
}
