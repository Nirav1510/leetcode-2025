// https://leetcode.com/problems/binary-tree-inorder-traversal/

void getInOrder(TreeNode *root, vector<int> &ans){
    if(!root){
        return;
    }

    getInOrder(root->left, ans);
    ans.push_back(root->val);
    getInOrder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    getInOrder(root, ans);
    return ans;
}

// ----------- iterative approach -----------
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;

    TreeNode* node = root;
    stack<TreeNode*> s;

    while(true){
        if(node){
            s.push(node);
            node = node->left;
        }else{
            if(s.empty()){
                break;
            }
            node = s.top();
            s.pop();

            ans.push_back(node->val);
            node = node->right;
        }
    }

    return ans;
}