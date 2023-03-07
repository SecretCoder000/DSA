int niceSubarray(int n, vector<int> &arr) {
    int i,count,mx;
    mx = 0;
    count = 1;
    i=0;
    while(i<n){
        if(arr[i] == count){
            mx = max(mx,count);
            count++;
        }

        else
            count = 1;
        i++;
    }
    return mx;
}