string findOrder(string dict[], int N, int V) {
    vector<vector<int>> adj(V);
    for(int i =1;i<N;i++){
        for(int j =0;j<dict[i].size() && j<dict[i-1].size();j++){
            if(dict[i-1][j] != dict[i][j]){
                adj[dict[i-1][j]-'a'].push_back(dict[i][j]-'a');
                break;
            }
        }
    }
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
    string arr;
    while (!que.empty()){
        int node = que.front();
        que.pop();
        arr.push_back(tolower(node+97));
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0)
                que.push(it);
        }
    }
    return arr;
}