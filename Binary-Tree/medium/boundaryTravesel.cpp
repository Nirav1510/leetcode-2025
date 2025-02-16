// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

bool isLeaf(Node* root){
    return !root->left && !root->right;
}

void getLeftView(Node* root, vector<int> &ans){
    if(!root || isLeaf(root)) return;
    
    ans.push_back(root->data);
    
    if(root->left){
        getLeftView(root->left, ans);
    }else{
        getLeftView(root->right, ans);
    }
    
}

void getLeafNodes(Node* root, vector<int> &ans){
    if(!root) return;
    
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    
    if(root->left){
        getLeafNodes(root->left, ans);
    }
    if(root->right){
            getLeafNodes(root->right, ans);
    }
}

void getRightView(Node* root, vector<int> &ans){
    if(!root || isLeaf(root)) return;
    
    if(root->right){
        getRightView(root->right, ans);
    }else{
        getRightView(root->left, ans);
    }
    
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    
    if(!root) return ans;
    
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
    
    getLeftView(root->left, ans);
    getLeafNodes(root, ans);
    getRightView(root->right, ans);
    
    return ans;
}