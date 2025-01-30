// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1


// Time Complexity: O(2NlogN), Space Complexity: O(N)
vector<int> replaceWithRank(vector<int> &arr, int N){
    vector<int> result(arr.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Push all elements along with their indices into the min-heap
    for (int i = 0; i < arr.size(); i++) {
        minHeap.push({arr[i], i});
    }

    unordered_map<int, int> rankMap;
    int rank = 1;

    // Extract elements from heap and assign ranks
    while (!minHeap.empty()) {
        int val = minHeap.top().first;
        int idx = minHeap.top().second;
        minHeap.pop();

        // If the value is not already assigned a rank, assign it
        if (rankMap.find(val) == rankMap.end()) {
            rankMap[val] = rank;
            rank++;
        }

        // Store the rank of the element at its original index
        result[idx] = rankMap[val];
    }

    return result;
}

// another solution
// Time Complexity: O(NlogN)+O(2N), Space Complexity: O(N)
vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;  // Create a copy of the original array to sort
    unordered_map<int, int> rankMap;
    
    // Sort the array in ascending order
    sort(sortedArr.begin(), sortedArr.end());
    
    // Assign ranks to elements based on sorted order
    int rank = 1;
    for (int i = 0; i < sortedArr.size(); ++i) {
        // If this element is not in the map, assign it a rank
        if (rankMap.find(sortedArr[i]) == rankMap.end()) {
            rankMap[sortedArr[i]] = rank++;
        }
    }

    // Replace original array elements with their ranks
    vector<int> result;
    for (int num : arr) {
        result.push_back(rankMap[num]);
    }
    
    return result;
}