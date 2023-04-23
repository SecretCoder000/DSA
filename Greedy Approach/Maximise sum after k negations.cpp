long long int maximizeSum(long long a[], int n, int k){
    sort(a,a+n);
    for(int i =0;i<n && k > 0;i++,k--){
        if(a[i] < 0)
            a[i] = -a[i];
        else
            break;
    }
    sort(a,a+n);
    if(k&1){
        a[0] = -a[0];
    }
    long long sum = 0;
    for(int i =0;i<n;i++)
        sum += a[i];
    return sum;
}