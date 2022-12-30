int solve(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a = n/3;
        int b = a;

        if(n-a-2*b == 1)
            a++;
        else if(n-a-2*b == 2)
            b++;
        cout<<a<<" "<<b<<endl;
    }
}