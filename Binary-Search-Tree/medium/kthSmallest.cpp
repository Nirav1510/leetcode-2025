// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

void inOrder(TreeNode* root, int k, int &count, int &ans){
    if (!root || count >= k) return; 

    inOrder(root->left, k, count, ans); 

    count++;  
    if (count == k) {
        ans = root->val;
        return; 
    }

    inOrder(root->right, k, count, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = -1, count = 0;

    inOrder(root, k, count, ans);

    return ans;
}