// https://leetcode.com/problems/binary-tree-right-side-view/

void findRightView(TreeNode *root, vector<int> &ans, int level, int &maxLevel){
    if(!root) return;

    if(maxLevel < level){
        ans.push_back(root->val);
        maxLevel = level;
    }

    findRightView(root->right, ans, level+1, maxLevel);
    findRightView(root->left, ans, level+1, maxLevel);
}

vector<int> rightSideView(TreeNode* root) {
    int maxLevel = -1, level = 0;
    vector<int> ans;

    findRightView(root, ans, level, maxLevel);
    return ans;
}