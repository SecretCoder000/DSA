void graphDSF(int node,vector<vector<int>> adj,vector<int> & vis,vector<int> & dfs){
    vis[node] = 1;
    dfs.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            graphDSF(it,adj,vis,dfs);
        }
    }
}