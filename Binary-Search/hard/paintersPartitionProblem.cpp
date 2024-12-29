bool isPossible(vector<int> &boards, int maxLength, int maxPainters){
    int painter = 1, length = 0;

    for(int b : boards){
        if(b > maxLength){
            return false;
        }

        length+=b;
        if(length > maxLength){
            painter++;
            length = b;
        }

        if(painter > maxPainters){
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k){
    int low = 0, high = 0, ans = 0;

    for(int b : boards){
        low = max(low, b);
        high += b;
    }

    while(low<=high){
        int mid = low + (high-low)/2;

        if(isPossible(boards, mid, k)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}