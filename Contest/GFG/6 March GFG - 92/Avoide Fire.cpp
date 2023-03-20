bool avoidFire(int n, int m, int x, int y, vector<vector<int>> &arr) {
    int my_time = (n-1-x)+(m-1-y);
    if(my_time == 0)
        return true;
    for(int i = x;i<n;++i){
        for(int j = y;j<m;++j){
            if(arr[i][j] == 1)
                return false;

            int dist = (i-x)+(j-y);

            int left = INT_MAX;

            for(int k = j-1;k>=0;k--){
                if(arr[i][k] == 1){
                    left = (j-k);
                    break;
                }
            }
            if(dist >= left) return false;

            int up = INT_MAX;
            for(int k = i-1;k>=0;k--){
                if(arr[k][j] == 1){
                    up = (i-k);
                    break;
                }
            }
            if(dist >= up) return false;
        }
    }
    return true;
}