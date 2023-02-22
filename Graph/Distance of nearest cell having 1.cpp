void bfs(queue<pair<pair<int,int>,int>> que,vector<vector<int>> & ans,vector<vector<int>> & vis){
    int n = ans.size()-1;
    int m = ans[0].size()-1;
    while(!que.empty()){
        int row = que.front().first.first;
        int col = que.front().first.second;
        int dist = que.front().second;
        ans[row][col] = dist;
        que.pop();
        if(row != 0 && vis[row-1][col] == 0){
            que.push({{row - 1, col}, dist + 1});
            vis[row-1][col] = 1;
        }
        if(row != n && vis[row+1][col] == 0){
            que.push({{row + 1, col}, dist + 1});
            vis[row+1][col] = 1;
        }
        if(col != 0 && vis[row][col-1] == 0){
            que.push({{row, col - 1},dist+1});
            vis[row][col-1] = 1;
        }
        if(col != m && vis[row][col+1] == 0){
            que.push({{row, col + 1},dist+1});
            vis[row][col+1] = 1;
        }
    }
}
vector<vector<int>>nearest(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans (n,vector<int>(m,0));
    vector<vector<int>> vis (n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> que;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j] == 1){
                grid[i][j] = 0;
                que.push({{i, j},0});
                vis[i][j] = 1;
            }
        }
    }
    bfs(que,ans,vis);
    return ans;
}