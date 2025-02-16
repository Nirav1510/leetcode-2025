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

// ------- using BFS ---------

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};

    map<int, vector<int>> mp; // Map keeps keys sorted
    queue<pair<TreeNode*, int>> q; // (Node, vertical level)

    q.push({root, 0}); // Root starts at vertical level 0

    while (!q.empty()) {
        int size = q.size();
        // Temp vector to maintain order in current level
        vector<pair<int, int>> temp;

        for (int i = 0; i < size; i++) {
            auto [node, vLevel] = q.front();
            q.pop();

            temp.push_back({vLevel, node->val});

            if (node->left) q.push({node->left, vLevel - 1});
            if (node->right) q.push({node->right, vLevel + 1});
        }

        // Sort temp by vertical level first, then left-to-right order
        sort(temp.begin(), temp.end());

        // Insert values into map
        for (auto [vLevel, val] : temp) {
            mp[vLevel].push_back(val);
        }
    }

    vector<vector<int>> ans;
    for (auto &entry : mp) {
        ans.push_back(entry.second);
    }

    return ans;
}