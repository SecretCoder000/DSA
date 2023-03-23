int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int> (n,0));
        int odd = 1;
        int even = 2;
        int count = (n*n+1)/2;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(count>0){
                    arr[i][j] = odd;
                    odd += 2;
                    count--;
                }else {
                    arr[i][j] = even;
                    even += 2;
                }
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}