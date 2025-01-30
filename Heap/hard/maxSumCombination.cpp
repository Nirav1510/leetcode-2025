// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> maxSumCombination(vector<int> &A, vector<int> &B, int C) {
    vector<int> result;
    int N = A.size();

    // Sort both arrays in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    // Max-Heap to store the sums and their corresponding indices (i, j)
    priority_queue<pair<int, pair<int, int>>> pq;

    // Start by adding the largest sum A[0] + B[0]
    pq.push({A[0] + B[0], {0, 0}});

    // Set to keep track of visited (i, j) pairs to avoid duplicates
    set<pair<int, int>> visited;
    visited.insert({0, 0});

    // Extract the largest sums from the heap C times
    while (C-- > 0) {
        auto top = pq.top();
        pq.pop();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        result.push_back(sum);

        // Consider the next possible sums by moving in the grid
        if (i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
            pq.push({A[i + 1] + B[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }
        if (j + 1 < N && visited.find({i, j + 1}) == visited.end()) {
            pq.push({A[i] + B[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return result;
}
