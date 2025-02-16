// https://leetcode.com/problems/symmetric-tree/

bool isValid(TreeNode* a, TreeNode* b){
    if(!a && !b){
        return true;
    }
    
    if(!a || !b || (a->val != b->val)){
        return false;
    }
    
    bool left = isValid(a->left, b->right);
    bool right = isValid(a->right, b->left);

    return left && right;
}

bool isSymmetric(TreeNode* root) {
    if(!root) return true;

    return isValid(root->left, root->right);
}