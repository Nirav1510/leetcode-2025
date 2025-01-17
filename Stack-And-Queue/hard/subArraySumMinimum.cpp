// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToLeft(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=0;i<n;i++){

        while(!s.empty() && arr[s.top()] > arr[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = i + 1;
        }else {
            ans[i] = i - s.top();
        }

        s.push(i);
    }
    return ans;
}

vector<int> nextSmallerToRight(vector<int> &arr, int n){
    stack<int> s;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){

        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = n - i;
        }else{
            ans[i] = s.top() - i;
        }

        s.push(i);
    }
    return ans;
}

int sumSubArrayMins(vector<int>& arr) {
    int total = 0, n = arr.size();
    int mod = 1e9 + 7;
    
    vector<int> nseLeft = nextSmallerToLeft(arr, n);
    vector<int> nseRight = nextSmallerToRight(arr, n);


    for(int i = 0; i < n; i++){
        total = (total + ((long long)arr[i] * nseLeft[i] * nseRight[i]) % mod) % mod;
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << sumSubArrayMins(arr) << endl;
    return 0;
}