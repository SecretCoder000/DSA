int saveFlowers(int n, vector<int> &arr, string s) {
    int i,j;
    i=j=0;
    int ans = 0;
    int sum = 0;
    int mn = INT_MAX;
    while (j < n){
        if(s[j] == '1') {
            sum += arr[j];
            mn = min(mn, arr[j]);
        }
        if(s[j] == '0' || j == n-1 ){
            if(sum > 0){
                if(i != 0 && arr[i-1] > mn){
                    sum = sum - mn+arr[i-1];
                }
                ans += sum;
            }
            sum = 0;
            i = j+1;
            mn = INT_MAX;
        }
        j++;
    }
    return  ans;
}