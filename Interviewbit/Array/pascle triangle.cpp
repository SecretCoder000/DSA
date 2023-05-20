vector<vector<int> > Solution::solve(int a) {
    vector<vector<int>> ans(a);
    for(int i =0;i<a;i++){
        int j = 1;
        vector<int> temp(i+1);
        temp[0] = 1;
        int n = i;
        int r = 1;
        while(j<=i){
            temp[j] = (temp[j-1]*n/r);
            j++;
            n--;
            r++;
        }
        ans[i] = temp;
    }
    return ans;
}
