int shortestXYDist(vector<vector<char>> grid, int N, int M) {
    vector<pair<int,int>> x,y;
    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            if(grid[i][j] == 'X')
                x.push_back({i,j});
            if(grid[i][j] == 'Y')
                y.push_back({i,j});
        }
    }
    int min = INT_MAX;
    for(int i =0;i<x.size();i++){
        for(int j =0;j<y.size();j++){
            int temp = abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second);
            min = min>temp?temp:min;
            if(min == 1)
                return 1;
        }
    }
    return min;
}
