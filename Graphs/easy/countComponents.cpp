void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;
    for(auto &neigh: adj[node]){
      if(!visited[neigh]){
        dfs(neigh, adj, visited);
      }
    }
  }

  int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for(auto &e: edges){
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(V, false);
    int components = 0;

    for(int i=0;i<V;i++){
      if(!visited[i]){
        components++;
        dfs(i, adj, visited);
      }
    }

    return components;
  }