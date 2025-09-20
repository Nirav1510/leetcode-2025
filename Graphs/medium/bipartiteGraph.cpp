bool bfs(int start, vector<int> &color, vector<vector<int>> &adj){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto neigh : adj[node]){
            if(color[neigh] == -1){
                color[neigh] = !color[node];
                q.push(neigh);
            }else if(color[neigh] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool dfs(int node, int currColor, vector<int> &color, vector<vector<int>> &adj){
    color[node] = currColor;
    
    for(auto &neigh : adj[node]){
        if(color[neigh] == -1){
            if (!dfs(neigh, 1-currColor, color, adj)){
                return false;
            } 
        }else if(color[neigh] == currColor){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);

    for(int i=0;i<V;i++){
        if(color[i] == -1){
            if(!dfs(i, 0, color, graph)){
                return false;
            }
        }
    }
    return true;
}