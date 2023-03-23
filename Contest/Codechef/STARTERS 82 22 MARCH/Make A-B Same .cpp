int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> brr(n);
        bool isOne = false;
        for(int i =0;i<n;i++){
            cin>>arr[i];
            if(!isOne && arr[i] == 1)
                isOne = true;
        }
        for(int i =0;i<n;i++)
            cin>>brr[i];
        bool flag = true;
        if(arr[0] != brr[0] || arr[n-1] != brr[n-1]){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i =1;i<n-1;i++){
            if(arr[i] == 1 && brr[i] == 0){
                flag = false;
                break;
            }else if(arr[i] == 0 && brr[i] == 1 && !isOne){
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
