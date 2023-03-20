int countWays(vector<vector<int>>& ranges) {
    sort(ranges.begin(),ranges.end());
    vector<int> ans = {ranges[0][0], ranges[0][1]};
    int j =1;
    for(int i =1;i<ranges.size();i++){
        if(ans[0] <= ranges[i][0] && ans[1] >= ranges[i][1])
            continue;
        else if( ans[1] >= ranges[i][0])
            ans[1] = ranges[i][1];
        else {
            ans = {ranges[i][0],ranges[i][1]};
            j++;
        }
    }
    int res = 1;
    int max = 1e9+7;
    while (j--)
        res = (res * 2)%max;
    return res;
}