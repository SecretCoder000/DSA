vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int>> ans(n,vector<int>(n,0));
    int count = 1;
    int max = n*n;
    int rStart,rEnd,cStart,cEnd;
    rStart=cStart=0;
    rEnd=cEnd=n-1;
    while(count<=max){
        for(int i = cStart;i<=cEnd && count <= max;i++,count++)
            ans[rStart][i] = count;
        rStart++;
        for(int i = rStart;i<=rEnd && count <= max;i++,count++)
            ans[i][cEnd] = count;
        cEnd--;
        for(int i = cEnd;i>=cStart && count <= max;i--,count++)
            ans[rEnd][i] = count;
        rEnd--;
        for(int i = rEnd;i>=rStart && count <= max;i--,count++)
            ans[i][cStart] = count;
        cStart++;
    }
    return ans;
}
