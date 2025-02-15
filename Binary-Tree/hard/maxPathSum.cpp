// https://leetcode.com/problems/binary-tree-maximum-path-sum/

int findMaxSum(TreeNode* root, int &ans){
    if(!root) return 0;

    int leftMax = max(0, findMaxSum(root->left, ans)); 
    int rightMax = max(0, findMaxSum(root->right, ans)); 

    ans = max(ans, leftMax + rightMax + root->val);

    return max(leftMax, rightMax) + root->val;
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    findMaxSum(root, ans);
    return ans;
}