void MakeZeros(vector<vector<int> >& arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> temp = arr;
    vector<int> drow = {0,0,-1,1};
    vector<int> dcol = {-1,1,0,0};
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(temp[i][j] != 0)
                continue;
            int sum = 0;
            for(int k = 0;k<4;k++){
                int row = i+drow[k];
                int col = j+dcol[k];
                if(row >= 0 && row <= n-1 && col >= 0 && col <= m-1){
                    sum += temp[row][col];
                    arr[row][col] = 0;
                }
            }
            arr[i][j] = sum;
        }
    }
}