// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

vector <int> bottomView(Node *root) {
    vector<int> ans;

    if(!root) return ans;
    
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* curr = it.first;
        int verticalLevel = it.second;
        
        mp[verticalLevel] = curr->data;
        
        if(curr->left){
            q.push({curr->left, verticalLevel - 1});
        }
        if(curr->right){
            q.push({curr->right, verticalLevel + 1});
        }
    }
    
    for(auto &it : mp){
        ans.push_back(it.second);
    }

    return ans;
}