vector<vector<int>> fourSum(vector<int>& a, long long int target) {
    sort(a.begin(),a.end());
    int n = a.size();

    vector<vector<int>> ans;

    if (n < 4) return ans;

    for(int i=0;i<n-3;i++){
        if(i>0 && a[i] == a[i-1]){
            continue;
        }

        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && a[j] == a[j-1]){
                continue;
            }
            
            long long int sum = target - (long long int)a[i] - (long long int)a[j];
            int low = j+1, high = n-1;

            while(low<high){
                long long int currSum = a[low] + a[high];

                if(currSum > sum){
                    high--;
                }else if(currSum < sum){
                    low++;
                }else{
                    ans.push_back({a[i],a[j],a[low],a[high]});

                    while(low < high && a[low] == a[low+1]) ++low;
                    while(low < high && a[high] == a[high-1]) --high;

                    low++;
                    high--;
                }
            }
        }
    }
    return ans;
}