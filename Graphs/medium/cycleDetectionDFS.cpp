bool detectCycleDFS(int src, int parent, vector<vector<int>> &adj, vector<bool> &visited){
    visited[src] = true;
    
    for(auto &neigh : adj[src]){
        if(!visited[neigh]){
            if(detectCycleDFS(neigh, src, adj, visited)){
                return true;
            }
        }else if(parent != neigh){
            return true;
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
            if(detectCycleDFS(i, -1, adj, visited)){
                return true;
            }
        }
    }
    return false;
}