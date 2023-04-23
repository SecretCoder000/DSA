int solve(vector<int>& bt) {
    sort(bt.begin(),bt.end());
    int n = bt.size();
    int sum = bt[0];
    for(int i =1;i<n-1;i++){
        bt[i] += bt[i-1];
        sum += bt[i];
    }
    return ceil(sum/n);
}