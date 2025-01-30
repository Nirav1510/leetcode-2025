#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minH;

    for(int n : nums){
        minH.push(n);

        if(minH.size() > k){
            minH.pop();
        }
    }
    return minH.top();
}

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxH;

    for(int n : nums){
        maxH.push(n);

        if(maxH.size() > k){
            maxH.pop();
        }
    }
    return maxH.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    cout << findKthSmallest(nums, k) << endl;
    return 0;
}