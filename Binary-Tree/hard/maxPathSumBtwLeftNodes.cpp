// https://www.geeksforgeeks.org/problems/maximum-path-sum/1

int findMaxLeafToLeafSum(Node* root, int &ans){
    if(!root) return 0;

    int leftMax = findMaxLeafToLeafSum(root->left, ans); 
    int rightMax = findMaxLeafToLeafSum(root->right, ans); 

    
    if (root->left && root->right) {
        ans = max(ans, leftMax + rightMax + root->data);
        return max(leftMax, rightMax) + root->data;
    }

    return root->data + (root->left ? leftMax : rightMax);
}

int maxPathSum(Node* root){
    int ans = INT_MIN;

    int result = findMaxLeafToLeafSum(root, ans);

    return (ans == INT_MIN) ? result : ans;
}