// https://leetcode.com/problems/boats-to-save-people/

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());

    int n = people.size();
    int left = 0, right = n-1, ans = 0;

    while(left<=right){
        if(people[left] + people[right] <= limit){
            left++;
        }
        right--;
        ans++;
    }
    return ans;
}