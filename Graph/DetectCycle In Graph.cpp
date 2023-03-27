https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//Usin BSF
bool bfs(int src ,vector<int> adj[],vector<int> & visited){
    queue<pair<int,int>> que;
    que.push({src,-1});
    visited[src] = 1;
    while(!que.empty()){
        auto temp = que.front();
        int node = temp.first;
        int parent = temp.second;
        que.pop();
        for(auto adjNode : adj[node]){
            if(visited[adjNode] == 0){
                visited[adjNode] = 1;
                que.push({adjNode,node});
            }else if(parent != adjNode)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V);
    for(int i =0;i<V;i++){
        if(visited[i] == 0){
            if(bfs(i,adj,visited))
                return true;
        }
    }
    return false;
}
//Using DFS
bool graphDSF(int node,vector<int> adj[],vector<int> & vis,int parent){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            if(graphDSF(it,adj,vis,node))
                return true;
        }else if(it != parent)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    for(int i =0;i<V;i++){
        if(visited[i] == 0){
            if(graphDSF(i,adj,visited,-1))
                return true;
        }
    }
    return false;
}