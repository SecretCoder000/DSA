bool canFinish(int V, vector<vector<int>>& pre) {
    vector<vector<int>> adj(V);
    for(int i =0;i<pre.size();i++)
        adj[pre[i][0]].push_back(pre[i][1]);
    vector<int> indeg(V,0);
    for(int i =0;i<V;i++){
        for(int j=0;j<adj[i].size();j++)
            indeg[adj[i][j]]++;
    }
    queue<int> que;
    for(int i =0;i<V;i++){
        if(indeg[i] == 0)
            que.push(i);
    }
    int count = 0;
    while (!que.empty()){
        int node = que.front();
        que.pop();
        count++;
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0)
                que.push(it);
        }
    }
    return count==V;
}