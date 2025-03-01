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

void getLeftViewIterative(Node* root, vector<int> &ans){
    if(!root || isLeaf(root)) return;
    Node* curr = root;
    
    while(curr){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }
        
        if(curr->left){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
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

void getRightViewIterative(Node* root, vector<int> &ans){
    if(!root || isLeaf(root)) return;
    
    Node* curr = root;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        
        if(curr->right){
            curr = curr->right;
        }else{
            curr = curr->left;
        }
    }
    
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
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