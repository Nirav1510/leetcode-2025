// https://leetcode.com/problems/same-tree/

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    
    if(!p || !q || p->val != q->val) return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
}