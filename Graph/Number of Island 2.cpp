bool isValid(int n,int m,int x,int y){
    if(x >= 0 && y >= 0 && x <= n-1 && y <= m-1)
        return true;
    return false;
}
vector<int> numOfIslands(int n, int m, vector<vector<int>> &adj) {
    Disjoint ds(n*m);
    vector<vector<int>> arr(n,vector<int>(m,0));
    int k = adj.size();
    vector<int> ans(k);
    int islandCount = 0;
    for(int i =0;i<k;i++){
        int row = adj[i][0];
        int col = adj[i][1];
        int u = row*n+col;
        if(arr[row][col] == 1){
            continue;
        }
        arr[row][col] = 1;
        islandCount++;
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        for(int j = 0;j<4;j++){
            int nrow = row+drow[j];
            int ncol = col+dcol[j];
            if(!isValid(n,m,nrow,ncol) || arr[nrow][ncol] == 0)
                continue;
            int v = nrow*n+ncol;
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionByRank(u,v);
                islandCount--;
            }
        }
        ans[i] = islandCount;
    }
    return ans;
}