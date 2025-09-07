void dfs(int node, vector<bool> &visited, vector<int> &ans, vector<int> adj[]){
    visited[node] = true;
    ans.push_back(node);

    for(auto &neigh : adj[node]){
        if(!visited[neigh]){
        dfs(neigh, visited, ans, adj);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(V, false);

    dfs(0, visited, ans, adj);

    return ans;
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> bfs;

    visited[0] = true;
    q.push(0);

    while(!q.empty()){
    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for(auto &neigh : adj[node]){
        if(!visited[neigh]){
        visited[neigh] = true;
        q.push(neigh);
        }
    }
    }

    return bfs;
}