long long int maxSum(int arr[], int n){
    sort(arr,arr+n);
    long long sum = 0;
    bool flag = true;
    int lo = 0;
    int hi = n-1;
    while (lo < hi){
        sum += abs(arr[lo]-arr[hi]);
        if(!flag)
            hi--;
        else
            lo++;
        flag = !flag;
    }
    sum += abs(arr[lo]-arr[0]);
    return sum;
}