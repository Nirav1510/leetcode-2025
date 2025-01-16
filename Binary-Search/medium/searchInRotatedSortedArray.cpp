// https://leetcode.com/problems/search-in-rotated-sorted-array/

int searchInRotatedSortedArray(vector<int>& a, int k) {
    int low = 0, high = a.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(a[mid] == k){
            return mid;
        }

        if(a[low] <= a[mid]){
            if(a[low] <= k && k <= a[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(a[mid] <= k && k <= a[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}

// with duplicates in rotated sorted array
bool search(vector<int>& a, int k) {
    int low = 0, high = a.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(a[mid] == k) return true;

        if(a[low] == a[mid] && a[mid] == a[high]){
            low++;
            high--;
            continue;
        }

        if(a[low] <= a[mid]){
            if(a[low] <= k && k<=a[mid]){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }else{
            if(a[mid] <=k && k<= a[high]){
                low = mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return false;
}