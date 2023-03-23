int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int mn = INT_MAX;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            mn = min(mn,arr[i]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == mn)
                count++;
        }
        cout<<(n-count)<<endl;
    }
    return 0;
}