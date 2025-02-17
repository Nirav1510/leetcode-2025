// https://www.geeksforgeeks.org/problems/geeks-training/1

int maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    // Base case: filling dp[0]
    dp[0][0] = max(arr[0][1], arr[0][2]); // Last task was 0, so pick max from 1,2
    dp[0][1] = max(arr[0][0], arr[0][2]); // Last task was 1, so pick max from 0,2
    dp[0][2] = max(arr[0][0], arr[0][1]); // Last task was 2, so pick max from 0,1
    dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]}); // Any task on day 0
    
    // DP transition
    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {  // Last task done
            dp[day][last] = 0; // Reset for this state
            for(int task = 0; task < 3; task++) { // Pick a task
                if(task != last) {  // Can't repeat the same task
                    int points = arr[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }
    
    return dp[n-1][3]; // Return max points when any task was done on last day
}