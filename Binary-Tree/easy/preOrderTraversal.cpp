// https://leetcode.com/problems/binary-tree-preorder-traversal/

void getPreOrder(TreeNode *root, vector<int> &ans){
    if(!root){
        return;
    }

    ans.push_back(root->val);
    getPreOrder(root->left, ans);
    getPreOrder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    getPreOrder(root, ans);
    return ans;
}

// ------- iterative approach ------
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;

    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();

        ans.push_back(curr->val);

        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }

    return ans;
}