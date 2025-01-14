// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1


// next-smaller-element to left
vector<int> leftSmaller(int n, int a[]){
    vector<int> ans(n,-1);
    stack<int> s;
    
    for(int i=0;i<n;i++){
        
        while(!s.empty() && s.top() >= a[i]){
            s.pop();
        }
        
        if(!s.empty() && s.top() < a[i]){
            ans[i] = s.top();
        }
        
        s.push(a[i]);
    }
    return ans;
}

// next-smaller-element to right
vector<int> rightSmaller(int n, int arr[]){
    vector<int> ans(n, -1);
    stack<int> s;

    for(int i=n-1;i>=0;i--){

        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if(!s.empty() && s.top() < arr[i]){
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }
    return ans;
}