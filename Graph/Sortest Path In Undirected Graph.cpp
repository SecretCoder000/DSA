vector<int> shortestPath(vector<vector<int>>& edges, int V,int M, int src){
    vector<vector<int>> adj(V);
    for(int i =0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(V);
    queue<pair<int,int>> que;
    vector<int> bfs(V,INT_MAX);
    que.push({src,0});
    visited[src] = 1;
    bfs[src] = 0;
    while (!que.empty()) {
        int v = que.front().first;
        int wt = que.front().second;
        que.pop();
        for (auto adjNode: adj[v]) {
            if (visited[adjNode] == 0){
                visited[adjNode] = 1;
                bfs[adjNode] = wt+1;
                que.push({adjNode,wt+1});
            }else
                bfs[adjNode] = min(bfs[adjNode],wt+1);
        }
    }
    for(int i =0;i<V;i++)
        if(bfs[i] == INT_MAX)
            bfs[i] = -1;
    return bfs;
}