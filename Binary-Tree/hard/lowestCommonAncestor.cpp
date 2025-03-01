// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;

    if(root == p || root == q){
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left && right){
        return root;
    }
    
    return left ? left : right;
}