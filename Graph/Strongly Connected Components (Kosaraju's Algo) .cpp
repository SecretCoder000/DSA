void graphDFS(int node,vector<vector<int>>& adj,vector<int> & vis,stack<int> & st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0)
            graphDFS(it,adj,vis,st);
    }
    st.push(node);
}
void graphDFSS(int node,vector<vector<int>>& adj,vector<int> & vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0)
            graphDFSS(it,adj,vis);
    }
}
int kosaraju(int V, vector<vector<int>>& adj){
    stack<int> st;
    vector<int> arr;
    vector<int> vis(V,0);
    for(int i =0;i<V;i++){
        if(vis[i] == 0)
            graphDFS(i,adj,vis,st);
    }
    vector<vector<int>> adjRev(V);
    for(int i =0;i<adj.size();i++){
        for(auto node : adj[i])
            adjRev[node].push_back(i);
    }
    vector<int> visR(V,0);
    int count = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(visR[node] == 0){
            graphDFSS(node,adjRev,visR);
            count++;
        }
    }
    return count;
}