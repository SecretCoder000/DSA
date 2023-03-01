void graphDSF(pair<int,int> node,vector<vector<char>> & ans,vector<vector<int>> & vis){
    int row = node.first;
    int col = node.second;
    int n = ans.size();
    int m = ans[0].size();
    vis[row][col] = 1;
    if(row != 0 && ans[row-1][col] == 'O' && vis[row-1][col] == 0)
        graphDSF({row - 1, col},ans, vis);
    if(row != n-1 && ans[row+1][col] == 'O' && vis[row+1][col] == 0)
        graphDSF({row + 1, col},ans, vis);
    if(col != 0 && ans[row][col-1] == 'O' && vis[row][col-1] == 0)
        graphDSF({row , col-1},ans, vis);
    if(col != m-1 && ans[row][col+1] == 'O' && vis[row][col+1] == 0)
        graphDSF({row , col+1},ans, vis);
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> grid){
    vector<vector<int>> vis(n,vector<int> (m,0));
    for(int j =0;j<m;j++){
        if(grid[0][j] == 'O' && vis[0][j] == 0)
            graphDSF({0,j},grid,vis);
    }
    for(int j =0;j<n;j++){
        if(grid[j][0] == 'O' && vis[j][0] == 0)
            graphDSF({j,0},grid,vis);
    }
    for(int j =0;j<m;j++){
        if(grid[grid.size()-1][j] == 'O' && vis[vis.size()-1][j] == 0)
            graphDSF({grid.size()-1,j},grid,vis);
    }
    for(int j =0;j<n;j++){
        if(grid[j][grid[0].size()-1] == 'O' && vis[j][vis[0].size()-1] == 0)
            graphDSF({j,grid[0].size()-1},grid,vis);
    }
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            if(grid[i][j] == 'O' && vis[i][j] == 0)
                grid[i][j] = 'X';
    return grid;
}