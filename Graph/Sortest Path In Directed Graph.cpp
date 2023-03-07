void graphDFS(int node,vector<vector<pair<int,int>>> adj,vector<int> & vis,stack<int> & st){
vis[node] = 1;
for(auto it : adj[node]){
if(vis[it.first]==0)
graphDFS(it.first,adj,vis,st);
}
st.push(node);
}
vector<int> shortestPath(int V,int M, vector<vector<int>>& edges){
    vector<vector<pair<int,int>>> adj(V);
    for(int i =0;i<M;i++)
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    stack<int> st;
    vector<int> vis(V,0);
    for(int i =0;i<V;i++){
        if(vis[i] == 0)
            graphDFS(i,adj,vis,st);
    }
    vector<int> arr(V,INT_MAX);
    arr[0] = 0;
    while(!st.empty() && st.top() != 0){
        int node = st.top();
        st.pop();
        arr[node] = -1;
    }
    while(!st.empty()){
        int node = st.top();
        st.pop();
        int dist = arr[node];
        for(auto it : adj[node])
            arr[it.first] = min(arr[it.first],dist+it.second);
    }
    for(int i =0;i<V;i++){
        if(arr[i] == INT_MAX)
            arr[i] = -1;
    }
    return arr;
}