// https://www.geeksforgeeks.org/problems/children-sum-parent/1

bool isLeaf(Node* root){
    return !root->left && !root->right;
}

bool isValidTree(Node* root){
    if (!root || isLeaf(root)) {
        return true;
    }
    
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    
    if(sum == root->data){
        return isValidTree(root->left) && isValidTree(root->right);
    }
    
    return false;
}

int isSumProperty(Node *root){
    return isValidTree(root) ? 1 : 0;
}