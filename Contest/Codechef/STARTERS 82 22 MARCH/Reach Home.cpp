int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(y<= 5*x)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}