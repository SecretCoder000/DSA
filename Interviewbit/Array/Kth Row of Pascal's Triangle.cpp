//
// Created by himan on 5/11/2023.
//

vector<int> Solution::getRow(int k) {
    vector<int> ans(k+1);
    int i = 1;
    ans[0] = 1;
    int n = k;
    int r = 1;
    while(i<=k){
        ans[i] = (ans[i-1]*n/r);
        n--;
        r++;
        i++;
    }
    return ans;
}
