int minimumTotal(vector<vector<int>>& arr) {
    int mini = arr[0][0];
    for(int i =1;i<arr.size();i++) {
        arr[i][0] += arr[i-1][0];
        arr[i][arr[i].size()-1] += arr[i-1][arr[i-1].size()-1];
        mini = min(arr[i][arr[i].size()-1],arr[i][0]);
        for(int j =1;j<arr[i].size()-1;j++) {
            arr[i][j] += min(arr[i-1][j],arr[i-1][j-1]);
            mini = min(mini,arr[i][j]);
        }
    }
    return mini;
}