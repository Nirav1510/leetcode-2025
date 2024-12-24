// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

int binarySearch(vector<int> &v, int &t, bool isSearchingLeft){
    int low = 0, high = v.size()-1, idx = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(v[mid] == t){
            idx = mid;

            if(isSearchingLeft){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else if(v[mid]>t){
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }
    return idx;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = {-1,-1};
    int leftMost = binarySearch(nums,target,true);
    int rightMost = binarySearch(nums,target,false);

    ans[0] = leftMost;
    ans[1] = rightMost;

    return ans;
}