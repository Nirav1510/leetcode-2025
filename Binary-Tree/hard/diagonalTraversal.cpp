// https://practice.geeksforgeeks.org/problems/diagonal-traversal-in-binary-tree/1

void solve(Node* root, int level, unordered_map<int, vector<int>> &mp){
    if(!root) return;
    
    mp[level].push_back(root->data);
    
    solve(root->left, level+1, mp);
    solve(root->right, level, mp);
}

vector<int> diagonal(Node *root) {
    if(!root) return {};
    
    unordered_map<int, vector<int>> mp;
    
    solve(root, 0, mp);
    
    int level = 0;
    vector<int> ans;
    while(mp.find(level) != mp.end()){
        vector<int> curr = mp[level];
        for(int c : curr) ans.push_back(c);
        level++;
    }    
    
    return ans;
}