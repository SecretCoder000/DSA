int MinimumEffort(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    pair<int,int> source = {0,0};
    pair<int,int> destination = {n-1,m-1};
    vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
    que.push({0,source});
    vis[source.first][source.second] = grid[0][0];
    int mn = INT_MAX;
    while (!que.empty()){
        int dist = que.top().first;
        auto node = que.top().second;
        que.pop();
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        for(int i =0;i<4;i++){
            int row = node.first+dr[i];
            int col = node.second+dc[i];
            if(row < 0 || row >= n || col < 0 || col >= m)
                continue;
            int temp = abs(grid[row][col]-grid[node.first][node.second]);
            temp =max(temp,dist);
            if(row == n-1 && col == m-1)
                mn = min(mn,temp);
            if(vis[row][col] > temp){
                vis[row][col] = temp;
                que.push({temp,{row,col}});
            }
        }
    }
    return mn;
}