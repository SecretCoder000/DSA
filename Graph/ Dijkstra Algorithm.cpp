vector<int> dijkstra(int V, vector<vector<int>> adj[], int src){
    vector<int> visited(V);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    vector<int> bfs(V,INT_MAX);
    que.push({0,src});
    visited[src] = 1;
    bfs[src] = 0;
    while (!que.empty()) {
        int v = que.top().second;
        int wt = que.top().first;
        que.pop();
        for (auto it: adj[v]) {
            int adjWt = it[1];
            int adjNode = it[0];
            if(wt+adjWt < bfs[adjNode]){
                bfs[adjNode] = wt+adjWt;
                que.push({bfs[adjNode],adjNode});
            }
        }
    }
    return bfs;
}