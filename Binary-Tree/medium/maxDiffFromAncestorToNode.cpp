// https://practice.geeksforgeeks.org/problems/max-difference-between-node-and-its-ancestor/1

int findMin(Node* root, int &ans){
    if (!root) return INT_MAX;  

    // Get min value from left and right subtree
    int leftMin = findMin(root->left, ans);
    int rightMin = findMin(root->right, ans);

    // Find the minimum value encountered so far
    int subtreeMin = min(leftMin, rightMin);

    // Update max difference (skip root->data - root->data case)
    if (subtreeMin != INT_MAX) {
        ans = max(ans, root->data - subtreeMin);
    }

    return min(root->data, subtreeMin);
}

int maxDiff(Node* root){
    int ans = INT_MIN;
    findMin(root, ans);
    return ans;
}
