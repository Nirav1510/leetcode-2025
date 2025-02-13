// https://leetcode.com/problems/diameter-of-binary-tree/

int findDiameter(TreeNode* root, int &diameter){
    if(!root) return 0;

    int left = findDiameter(root->left, diameter);
    int right = findDiameter(root->right, diameter);

    diameter = max(diameter, left+right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int diameter = 0;

    findDiameter(root, diameter);

    return diameter;
}