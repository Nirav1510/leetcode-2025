// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

int findCeil(Node* root, int t) {
    if (root == NULL) return -1;

    int ans = -1;
    
    while(root){
        int val = root->data;
        if(val == t){
            return t;
        }else if(val > t){
            ans = val;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    
    return ans;
}