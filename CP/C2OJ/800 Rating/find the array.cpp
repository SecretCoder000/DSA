int solve(int n){
    if(n == 1)
        return n;
    else if (n <= 4)
        return 2;
    else {
        int sum = 1;
        int prev = 0;
        int count = 0;
        int i = 1;
        while (sum <= n){
            prev = sum;
            i += 2;
            sum += i;
            count++;
        }
        return abs(prev-n) > 0?count+1:count;
    }
}

