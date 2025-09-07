bool detectCycleBfs(int src, vector<vector<int>> &adj, vector<bool> &visited){
    visited[src] = true;
    queue<pair<int, int>> q;
    
    q.push({src, -1});
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto &neigh : adj[node]){
            if(!visited[neigh]){
                visited[neigh] = true;
                q.push({neigh, node});
            }else if(parent != neigh){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);
    
    for(auto &it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(detectCycleBfs(i, adj, visited)){
                return true;
            }
        }
    }
    return false;
}