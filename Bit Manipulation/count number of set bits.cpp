int solve(int n){
    int ctn = 0;
    while (n > 0){
        n = n&(n-1);
        ctn++;
    }
    return ctn;
}