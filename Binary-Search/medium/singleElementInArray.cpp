// https://leetcode.com/problems/single-element-in-a-sorted-array

int singleNonDuplicate(vector<int>& a) {
    int low = 0, high = a.size()-1, n = a.size();

    if (n == 1) return a[0];
    if (a[0] != a[1]) return a[0];
    if (a[n - 1] != a[n - 2]) return a[n - 1];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] != a[mid-1] && a[mid] != a[mid+1]){
            return a[mid];
        }

        if((mid%2 == 0 && a[mid] == a[mid+1]) || (mid%2 ==1 && a[mid] == a[mid-1])){
            low = mid+1;
        }else{
            high=mid-1;
        }
        
    }
    return -1;
}