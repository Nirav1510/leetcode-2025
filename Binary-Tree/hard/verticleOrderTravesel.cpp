// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

void dfs(TreeNode* root, int verticalLevel, int level, int &minVerticalLevel, int &maxVerticalLevel, map<int, vector<pair<int, int>>> &mp) {
    if (!root) return;

    // Store (level, value) pair
    mp[verticalLevel].push_back({level, root->val});

    minVerticalLevel = min(minVerticalLevel, verticalLevel);
    maxVerticalLevel = max(maxVerticalLevel, verticalLevel);

    dfs(root->left, verticalLevel - 1, level + 1, minVerticalLevel, maxVerticalLevel, mp);
    dfs(root->right, verticalLevel + 1, level + 1, minVerticalLevel, maxVerticalLevel, mp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int, int>>> mp;
    int minVerticalLevel = 0, maxVerticalLevel = 0;

    dfs(root, 0, 0, minVerticalLevel, maxVerticalLevel, mp);

    vector<vector<int>> ans;

    for (int verticalLevel = minVerticalLevel; verticalLevel <= maxVerticalLevel; verticalLevel++) {
        vector<pair<int, int>> curr = mp[verticalLevel];

        // Sort by level first, then by value
        sort(curr.begin(), curr.end());

        vector<int> sortedValues;
        for (auto &it : curr) {
            sortedValues.push_back(it.second);
        }
        ans.push_back(sortedValues);
    }

    return ans;
}