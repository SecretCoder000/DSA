long long coloredCells(int n) {
    if(n <= 1)
        return n;
    long long sum = 0;
    int i = 1;
    while(i <= 2*n-3){
        sum += 2*i;
        i += 2;
    }
    sum += i;
    return sum;
}