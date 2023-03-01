bool graphDFS(int node,vector<int> adj[],vector<int> & vis,vector<int> & path){
    vis[node] = 1;
    path[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            if(graphDFS(it,adj,vis,path))
                return true;
        }else if(path[it] == 1)
            return true;
    }
    path[node]= 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V+1,0);
    vector<int> path(V+1,0);
    for(int i =0;i<V;i++){
        if(visited[i] == 0){
            if(graphDFS(i,adj,visited,path))
                return true;
        }
    }
    return false;
}