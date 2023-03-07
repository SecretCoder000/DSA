int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    map<int,vector<pair<int,int>>> adj;
    for(int i =0;i<n;i++){
        int s = flights[i][0];
        int d = flights[i][1];
        int cost = flights[i][2];
        adj[s].push_back({d,cost});
    }
    int mn = INT_MAX;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
    que.push({0, {src,K}});
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    while (!que.empty()){
        auto node = que.top();
        que.pop();
        int cost = node.first;
        int s = node.second.first;
        int k = node.second.second;
        if(k < 0)
            continue;
        for(auto it : adj[s]){
            if(it.first == dst){
                mn = min(mn,cost+it.second);
            }
            if(dist[it.first] > cost+it.second){
                dist[it.first] = cost+it.second;
                que.push({dist[it.first],{it.first,k-1}});
            }
        }
    }
    return mn==INT_MAX?-1:mn;
}