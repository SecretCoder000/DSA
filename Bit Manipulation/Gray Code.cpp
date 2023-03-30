//GFG
vector<string> solve(int n,vector<string> arr){
    if(n == 1)
        return arr;
    vector<string> ans;
    for(auto it : arr){
        string str = '0' + it;
        ans.push_back(str);
    }
    for(int i = arr.size()-1;i>=0;i--){
        string str = '1' + arr[i];
        ans.push_back(str);
    }
    return solve(n-1,ans);
}
vector<string> graycode(int n){
    vector<string> arr = {"0","1"};
    return solve(n,arr);
}

//Leetcode
vector<int> solve(int n,int i){
    if(i == 0) {
        int f = n;
        int s = n | 1;
        return {f, s};
    }
    vector<int> left = solve(n,i-1);
    vector<int> right =  solve(n|(1<<i),i-1);
    vector<int> ans;
    ans.push_back(left[0]);
    for(auto it : right)
        ans.push_back(it);
    for(int i = left.size()-1;i>=1;i--)
        ans.push_back(left[i]);
    return ans;
}
vector<int> grayCode(int n) {
    return solve(0,n-1);
}
