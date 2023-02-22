void bfs(int row,int col,vector<vector<int>> & grid,vector<vector<int>> & vis,int newColour){
    queue<pair<int,int>> que;
    que.push({row,col});
    vis[row][col] = 1;
    int oldColour = grid[row][col];
    grid[row][col] = newColour;
    int n = grid.size()-1;
    int m = grid[0].size()-1;

    while(!que.empty()){
        int row = que.front().first;
        int col = que.front().second;
        que.pop();
        if(row != 0 && vis[row-1][col] == 0 && grid[row-1][col] == oldColour){
            que.push({row-1,col});
            vis[row-1][col] = 1;
            grid[row-1][col] = newColour;
        }
        if(row != n && vis[row+1][col] == 0 && grid[row+1][col] == oldColour){
            que.push({row+1,col});
            vis[row+1][col] = 1;
            grid[row+1][col] = newColour;
        }
        if(col != 0 && vis[row][col-1] == 0 && grid[row][col-1] == oldColour){
            que.push({row,col-1});
            vis[row][col-1] = 1;
            grid[row][col-1] = newColour;
        }
        if(col != m && vis[row][col+1] == 0 && grid[row][col+1] == oldColour){
            que.push({row,col+1});
            vis[row][col+1] = 1;
            grid[row][col+1] = newColour;
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    bfs(sr,sc,image,vis,newColor);
    return image;
}