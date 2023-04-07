void transpose(vector<vector<int>> & arr){
    int n = arr.size();
    for(int i =0;i<n-1;i++)
        for(int j =i+1;j<n;j++)
            swap(arr[i][j],arr[j][i]);
}
void rotate(vector<vector<int>>& arr) {
    transpose(arr);
    for(int i =0;i<arr.size();i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}
