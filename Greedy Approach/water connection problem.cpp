vector<int> bfs(int start,vector<vector<pair<int,int>>> & adj,vector<int> & vis){
queue<int> que;
que.push(start);
int minDiameter = INT_MAX;
int lastHouse;
while (!que.empty()){
int node = que.front();
que.pop();
for(auto it : adj[node]){
if(vis[it.first] == 0){
que.push(it.first);
minDiameter = min(minDiameter,it.second);
lastHouse = it.first;
}
}
}
return {start,lastHouse,minDiameter};
}
vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){
    vector<vector<pair<int,int>>> adj(n+1);
    set<int> noStart;
    for(int i =0;i<p;i++){
        adj[a[i]].push_back({b[i],d[i]});
        noStart.insert(b[i]);
    }
    vector<int> vis(n+1,0);
    vector<vector<int>> ans;
    for(int i = 1;i<=n;i++){
        if(noStart.find(i) == noStart.end() && vis[i] == 0 && adj[i].size() > 0)
            ans.push_back(bfs(i,adj,vis));
    }
    return ans;
}