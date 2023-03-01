bool graphBFS(int start,vector<int> adj[],vector<int> & visited) {
    queue<int> que;
    que.push(start);
    visited[start] = 0;
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (auto adjNode: adj[node]) {
            if (visited[adjNode] == -1) {
                visited[adjNode] = visited[node]==0?1:0;
                que.push(adjNode);
            }else if(visited[adjNode] == visited[node])
                return false;
        }
    }
    return true;
}
bool graphDFS(int node,vector<int> adj[],vector<int> & visited,int parent) {
    visited[node] = parent;
    for (auto adjNode: adj[node]) {
        if (visited[adjNode] == -1) {
            if(!graphDFS(adjNode,adj,visited,!visited[node]))
                return false;
        }else if(visited[adjNode] == parent)
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    vector<int> visited(V,-1);
    for(int i =0;i<V;i++){
        if(visited[i] ==-1)
            if(!graphDFS(i,adj,visited,0))
                return false;
    }
    return true;
}
