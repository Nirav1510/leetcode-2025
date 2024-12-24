// https://leetcode.com/problems/search-insert-position/

int searchInsert(vector<int>& a, int k) {
    int low = 0, high = a.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(a[mid] == k){
            return mid;
        }else if(a[mid] > k){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}