int solve(string A, string B) {
    long long a = stoll(A);
    long long b = stoll(B);
    long long ans = 0;
    for(long long i = a;i<=b;i++){
        long long sum = 0;
        long long temp = i;
        float min,max;
        min = temp%10;
        max = min;
        while(temp>0){
            long long r = temp%10;
            sum ^= r;
            temp /= 10;
            min = min>r?r:min;
            max = max<r?r:max;
        }
        float check = sum;
        float check2 = (min+max)/2.0;
        if(check > check2)
            ans++;
    }
    return ans%1000000007;
}