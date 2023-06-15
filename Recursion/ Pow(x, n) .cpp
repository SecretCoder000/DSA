#define ll long long

ll m = 1e9+7;
//You need to complete this fucntion
ll solve(int n,int r,ll ans,int power){
    if(power == r)
        return ans;
    if(power*2 > r)
        return (ans*solve(n,r-power,n,1))%m;
    else
        return solve(n,r,(ans*ans)%m,power*2);
}
ll power(int N,int R){
    return solve(N,R,N,1);
}