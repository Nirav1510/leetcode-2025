// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

void inOrderTraversal(TreeNode* root, vector<int>& inOrder) {
    if (!root) return;

    inOrderTraversal(root->left, inOrder);

    inOrder.push_back(root->val);

    inOrderTraversal(root->right, inOrder);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> inOrder;
    inOrderTraversal(root, inOrder);

    int left = 0, right = inOrder.size()-1;

    while(left < right){
        int sum = inOrder[left] + inOrder[right];

        if(sum == k){
            return true;
        }else if(sum > k){
            right--;
        }else{
            left++;
        }
    }
    return false;
}