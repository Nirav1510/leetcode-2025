// https://leetcode.com/problems/number-of-provinces

void dfs(int node, vector<int> adj[], vector<bool> &visited){
    visited[node] = true;
    for(auto &neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh, adj, visited);
        }
    }
}

void bfs(int src, vector<int> adj[], vector<bool> &visited){
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &neigh : adj[node]){
            if(!visited[neigh]){
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<int> adj[V];
    vector<bool> visited(V, false);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(isConnected[i][j] == 1 && i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    int count = 0;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            count++;
            dfs(i, adj, visited); // using dfs
            // bfs(i, adj, visited); // using bfs
        }
    }
    return count;
}