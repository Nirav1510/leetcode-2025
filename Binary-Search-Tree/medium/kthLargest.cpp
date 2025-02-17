// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

void reverseInOrder(TreeNode* root, int k, int &count, int &ans){
    if (!root || count >= k) return; 

    reverseInOrder(root->right, k, count, ans); 

    count++;  
    if (count == k) {
        ans = root->val;
        return; 
    }

    reverseInOrder(root->left, k, count, ans);
}

int kthLargest(TreeNode* root, int k) {
    int ans = -1, count = 0;

    reverseInOrder(root, k, count, ans);

    return ans;
}