// https://leetcode.com/problems/count-complete-tree-nodes/

void solve(TreeNode* root, int &ans){
    if(!root) return;

    ans++;
    solve(root->left, ans);
    solve(root->right, ans);
}

int countNodes(TreeNode* root) {
    int ans = 0;
    if(!root) return ans;

    solve(root, ans);
    return ans;
}