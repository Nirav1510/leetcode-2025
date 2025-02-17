// https://geeksforgeeks.org/problems/floor-in-bst/1

int floor(Node* root, int x) {
    int ans = -1;
    
    while(root){
        int val = root->data;
        
        if(val == x){
            return x;
        }else if(val > x){
            root = root->left;
        }else{
            ans = val;
            root = root->right;
        }
    }
    return ans;
}