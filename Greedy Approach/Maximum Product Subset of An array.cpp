long long int findMaxProduct(vector<int>&a, int n){
    long long pro = LONG_LONG_MAX;
    bool isZero = false;
    int countNegative = 0;
    int minNegative = INT_MIN;
    int mod = 1e9+7;
    for(int i =0;i<n;i++){
        if(a[i] == 0 ){
            isZero = true;
            continue;
        }
        if(a[i] < 0){
            countNegative++;
            minNegative = max(minNegative,a[i]);
        }
        if(pro == LONG_LONG_MAX)
            pro = a[i];
        else
            pro = (pro*a[i])%mod;
    }
    if(pro == LONG_LONG_MAX)
        return 0;
    if(pro > 0)
        return pro;
    if(countNegative == 1 && isZero && n == 2)
        return 0;
    else
        return pro/minNegative;
}