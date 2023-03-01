//Using DFS
void graphDFS(int node,vector<int> adj[],vector<int> & vis,stack<int> & st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0)
            graphDFS(it,adj,vis,st);
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> arr;
    vector<int> vis(V,0);
    for(int i =0;i<V;i++){
        if(vis[i] == 0)
            graphDFS(i,adj,vis,st);
    }
    while (!st.empty()){
        arr.push_back(st.top());
        st.pop();
    }
    return arr;
}

//Using BFS
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> st;
    vector<int> vis(V,0);
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
    vector<int> arr;
    while (!que.empty()){
        int node = que.front();
        que.pop();
        arr.push_back(node);
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0)
                que.push(it);
        }
    }
    return arr;
}
