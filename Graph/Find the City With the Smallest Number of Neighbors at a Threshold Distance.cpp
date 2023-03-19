int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> arr(n,vector<int> (n,1e8));
    for(int i =0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        arr[u][v] = arr[v][u] = wt;
    }
    for(int i =0;i<n;i++)
        arr[i][i] = 0;
    for(int k = 0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
    pair<int,int> ans = {INT_MAX,INT_MAX};
    for(int i =0;i<n;i++){
        int count = 0;
        for(int j =0;j<n;j++){
            if(arr[i][j] == 1e8)
                continue;
            else if (arr[i][j] <= distanceThreshold)
                count++;
        }
        if(count <= ans.first)
            ans = {count,i};
    }
    return ans.second;
}