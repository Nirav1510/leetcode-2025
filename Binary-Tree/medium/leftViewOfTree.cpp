// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void findLeftView(Node *root, vector<int> &ans, int level, int &maxLevel){
    if(!root) return;

    if(maxLevel < level){
        ans.push_back(root->data);
        maxLevel = level;
    }

    findLeftView(root->left, ans, level+1, maxLevel);
    findLeftView(root->right, ans, level+1, maxLevel);
}

vector<int> leftView(Node *root) {
    int maxLevel = -1, level = 0;
    vector<int> ans;

    findLeftView(root, ans, level, maxLevel);
    return ans;
}