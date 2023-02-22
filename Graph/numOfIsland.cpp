void bsf(int row,int col,vector<vector<char>> & grid,vector<vector<int>> & vis){
    queue<pair<int,int>> que;
    que.push({row,col});
    vis[row][col] = 1;
    int n = grid.size()-1;
    int m = grid[0].size()-1;
    while(!que.empty()){
        int row = que.front().first;
        int col = que.front().second;
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                int nrow = row+i;
                int ncol = col+j;
                if(nrow >= 0 && nrow <= n && ncol>=0 && ncol <= m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                    que.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
    int count = 0;
    for(int k =0;k<n;k++){
        for(int l =0;l<m;l++){
            if(grid[k][l] == '1' && vis[k][l] == 0){
                count++;
                bsf(k,l,grid,vis);
            }
        }
    }
    return count;
}