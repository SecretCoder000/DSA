int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    int buy = arr[0];
    for(int i = 1;i<n;i++){
        if(buy > arr[i])
            buy = arr[i];
        else if(arr[i]-buy > ans)
            ans = arr[i]-buy;
    }
    return ans;
}