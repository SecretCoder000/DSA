void graphBSF(pair<int,int> bais,vector<vector<int>> & grid,vector<vector<int>> & vis,set<vector<pair<int,int>>> & ans) {
int n = grid.size()-1;
int m = grid[0].size()-1;
queue<pair<int,int>> que;
vector<pair<int,int>> temp;
que.push(bais);
vis[bais.first][bais.second] = 1;
while (!que.empty()) {
int row = que.front().first;
int col = que.front().second;
temp.push_back({bais.first-row,bais.second-col});
que.pop();
if(row != 0 && vis[row-1][col] == 0 && grid[row-1][col] == 1){
que.push({row-1,col});
vis[row-1][col] = 1;
}
if(row != n && vis[row+1][col] == 0 && grid[row+1][col] == 1){
que.push({row+1,col});
vis[row+1][col] = 1;
}
if(col != 0 && vis[row][col-1] == 0 && grid[row][col-1] == 1){
que.push({row,col-1});
vis[row][col-1] = 1;
}
if(col != m && vis[row][col+1] == 0 && grid[row][col+1] == 1){
que.push({row,col+1});
vis[row][col+1] = 1;
}
}
ans.insert(temp);
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> ans;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j] == 1 && vis[i][j] == 0){
                graphBSF({i,j},grid,vis,ans);
            }
        }
    }
    return ans.size();
}