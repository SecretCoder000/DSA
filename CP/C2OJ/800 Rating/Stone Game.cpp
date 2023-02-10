int solve(vector<int> arr){
    int n = arr.size();
    pair<int,int> mn = {INT_MAX,-1};
    pair<int,int> mx = {INT_MIN,-1};
    for(int i =0;i<n;i++){
        mn = mn.first>arr[i]?pair<int,int>{arr[i],i}:mn;
        mx = mx.first<arr[i]?pair<int,int>{arr[i],i}:mx;
    }
    int i = mn.second;
    int j = mx.second;
    if(i>j)
        swap(i,j);
    int a = max(i,j)+1;
    int b = max(n-1-i,n-1-j)+1;
    int c = i+n+1-j;
    return min({a,b,c});
}



