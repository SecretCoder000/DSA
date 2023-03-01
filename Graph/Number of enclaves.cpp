void graphDSF(pair<int,int> node,vector<vector<int>> & ans,vector<vector<int>> & vis){
    int row = node.first;
    int col = node.second;
    int n = ans.size();
    int m = ans[0].size();
    vis[row][col] = 1;
    if(row != 0 && ans[row-1][col] == 1 && vis[row-1][col] == 0)
        graphDSF({row - 1, col},ans, vis);
    if(row != n-1 && ans[row+1][col] == 1 && vis[row+1][col] == 0)
        graphDSF({row + 1, col},ans, vis);
    if(col != 0 && ans[row][col-1] == 1 && vis[row][col-1] == 0)
        graphDSF({row , col-1},ans, vis);
    if(col != m-1 && ans[row][col+1] == 1 && vis[row][col+1] == 0)
        graphDSF({row , col+1},ans, vis);
}
int numberOfEnclaves(vector<vector<int>> & grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
    for(int j =0;j<m;j++){
        if(grid[0][j] == 1 && vis[0][j] == 0)
            graphDSF({0,j},grid,vis);
    }
    for(int j =0;j<n;j++){
        if(grid[j][0] == 1 && vis[j][0] == 0)
            graphDSF({j,0},grid,vis);
    }
    for(int j =0;j<m;j++){
        if(grid[grid.size()-1][j] == 1 && vis[vis.size()-1][j] == 0)
            graphDSF({grid.size()-1,j},grid,vis);
    }
    for(int j =0;j<n;j++){
        if(grid[j][grid[0].size()-1] == 1 && vis[j][vis[0].size()-1] == 0)
            graphDSF({j,grid[0].size()-1},grid,vis);
    }
    int count = 0;
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            if(grid[i][j] == 1 && vis[i][j] == 0)
                count++;
    return count;
}