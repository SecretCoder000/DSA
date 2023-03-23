bool isValid(int n,int m,int x,int y){
    if(x >= 0 && y >= 0 && x <= n-1 && y <= m-1)
        return true;
    return false;
}
int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    Disjoint ds(n*m);
    vector<pair<int,int>> coord;
    for(int row =0;row<n;row++){
        for(int col = 0;col<m;col++){
            if(grid[row][col] == 0){
                coord.push_back({row,col});
            }else {
                vector<int> drow = {-1,0,1,0};
                vector<int> dcol = {0,1,0,-1};
                int u = row*m+col;
                for(int j = 0;j<4;j++){
                    int nrow = row+drow[j];
                    int ncol = col+dcol[j];
                    if(!isValid(n,m,nrow,ncol) || grid[nrow][ncol] == 0)
                        continue;
                    int v = nrow*m+ncol;
                    if(ds.findParent(u) != ds.findParent(v))
                        ds.unionBySize(u,v);
                }
            }
        }
    }
    int mx = INT_MIN;
    for(int i =0;i<coord.size();i++){
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        set<int> parent;
        for(int k =0;k<4;k++){
            int row = coord[i].first+drow[k];
            int col = coord[i].second+dcol[k];
            if(!isValid(n,m,row,col) || grid[row][col] == 0)
                continue;
            int u = row*m+col;
            parent.insert(ds.findParent(u));
        }
        int size = 1;
        for(auto it : parent)
            size += ds.findSize(it);
        mx = max(mx,size);
    }
    return mx;
}