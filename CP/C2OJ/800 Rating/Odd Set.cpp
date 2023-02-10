int solve(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int arr[2*n];
        int o,e;
        o= e = 0;
        for(int i =0;i<2*n;i++){
            cin>>arr[i];
            if(arr[i]%2 == 0)
                e++;
            else
                o++;
        }
        if(o == e)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}