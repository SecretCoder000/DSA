int solve(vector<int> arr){
    pair<int,int> f,s;
    f=s={-1,-1};
    for(int i =0;i<arr.size();i++){
        if(f.first == -1){
            f.first = arr[i];
            f.second=i;
        }else if(arr[i] != f.first && s.first == -1){
            if(i == arr.size()-1)
                return i+1;
            s.first = arr[i];
            s.second=i;
        }
        else if(arr[i] == f.first && s.first != -1)
            return s.second+1;
        else if(arr[i] == s.first && f.first != -1)
            return f.second+1;
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i =0;i<n;i++)
            cin>>arr[i];
        cout<<solve(arr)<<endl;
    }
}