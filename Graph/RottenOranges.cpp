https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
int bfs(queue<pair<pair<int,int>,int>> que,vector<vector<int>> & grid,vector<vector<int>> & vis,int & count){
    int n = grid.size()-1;
    int m = grid[0].size()-1;
    int ans = -1;
    while(!que.empty()){
        int row = que.front().first.first;
        int col = que.front().first.second;
        int time = que.front().second;
        ans = max(ans,time);
        que.pop();
        if(row != 0 && vis[row-1][col] == 0 && grid[row-1][col] == 1){
            que.push({{row - 1, col}, time + 1});
            vis[row-1][col] = 1;
            grid[row-1][col] = 2;
            count--;
        }
        if(row != n && vis[row+1][col] == 0 && grid[row+1][col] == 1){
            que.push({{row + 1, col}, time + 1});
            vis[row+1][col] = 1;
            grid[row+1][col] = 2;
            count--;
        }
        if(col != 0 && vis[row][col-1] == 0 && grid[row][col-1] == 1){
            que.push({{row, col - 1}, time + 1});
            vis[row][col-1] = 1;
            grid[row][col-1] = 2;
            count--;
        }
        if(col != m && vis[row][col+1] == 0 && grid[row][col+1] == 1){
            que.push({{row, col + 1}, time + 1});
            vis[row][col+1] = 1;
            grid[row][col+1] = 2;
            count--;
        }
    }
    return ans;
}
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>> que;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 2){
                vis[i][j] = 1;
                que.push({{i, j}, 0});
            }
            if(grid[i][j] == 1)
                count++;
        }
    }
    int ans = bfs(que,grid,vis,count);
    return count==0?ans:-1;
}