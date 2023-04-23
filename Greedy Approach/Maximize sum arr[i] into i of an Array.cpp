class Solution{
public:
    int Maximize(int a[],int n)
    {
        // Complete the 
        sort(a,a+n);
        long long int sum=0;
        long long int mod = pow(10,9)+7;
        for(long long int i=0;i<n;i++){
            sum += a[i]*i;
        }
        return sum%mod;
    }
};