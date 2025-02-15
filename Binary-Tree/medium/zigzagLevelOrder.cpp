// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<TreeNode*> q;
    bool isLeftToRight = true;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            level[i] = curr->val;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        if(isLeftToRight){
            ans.push_back(level);
        }else{
            reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        isLeftToRight = !isLeftToRight;
    }

    return ans;
}