bool graphDFS(int node,vector<int> adj[],vector<int> & vis,vector<int> & path,set<int> & arr){
    vis[node] = 1;
    path[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            if(graphDFS(it,adj,vis,path,arr))
                return true;
        }else if(path[it] == 1)
            return true;
    }
    arr.insert(node);
    path[node]= 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> visited(V+1,0);
    vector<int> path(V+1,0);
    set<int> arr;
    for(int i =0;i<V;i++){
        if(visited[i] == 0)
            graphDFS(i,adj,visited,path,arr);
    }
    vector<int> ans = {arr.begin(),arr.end()};
    return ans;
}