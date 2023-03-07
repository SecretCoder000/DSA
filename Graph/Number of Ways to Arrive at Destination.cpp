int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<long long,long long>>> adj(n);
    for(long long i =0;i<roads.size();i++){
        long long s = roads[i][0];
        long long d = roads[i][1];
        long long c = roads[i][2];
        adj[s].push_back({d,c});
        adj[d].push_back({s,c});
    }
    int mod = (1e9+7);
    vector<long long> dist(n,1e18),ways(n,0);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> que;
    que.push({0,0});
    dist[0] = 0;
    ways[0] = 1;
    while (!que.empty()){
        long long time = que.top().first;
        long long src = que.top().second;
        que.pop();
        for(auto it : adj[src]){
            long long temp = time+it.second;
            if(dist[it.first] > temp){
                dist[it.first] = temp;
                ways[it.first] = ways[src];
                que.push({temp,it.first});
            }else if(dist[it.first] == temp){
                ways[it.first] = (ways[it.first]+ways[src])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}