int getSecondLargest(vector<int> &arr) {
    int first = -1, second = -1;
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }else if(arr[i]<first && arr[i]>second){
            second = arr[i];
        }
    }
    return second;
}