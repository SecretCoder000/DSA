void stockBuySell(int arr[], int n) {
    int buy,x;
    buy = 0;
    x = 1;
    for(int i = 0;i<n;i++){
        if(arr[i] < arr[buy] && buy < i){
            buy = i;
        }
        if(buy < i && arr[i+1] < arr[i]){
            cout<<"("<<buy<<" "<<i<<")"<<" ";
            buy = i+1;
            x = 0;
        }
        if(i == n-1 && buy < i && arr[i] > arr[buy]){
            cout<<"("<<buy<<" "<<i<<")"<<" ";
            buy = i+1;
            x = 0;
        }
    }
    if(x == 1)
        cout<<"No Profit";
    cout<<endl;
}void stockBuySell(int arr[], int n) {
    int buy,x;
    buy = 0;
    x = 1;
    for(int i = 0;i<n;i++){
        if(arr[i] < arr[buy] && buy < i){
            buy = i;
        }
        if(buy < i && arr[i+1] < arr[i]){
            cout<<"("<<buy<<" "<<i<<")"<<" ";
            buy = i+1;
            x = 0;
        }
        if(i == n-1 && buy < i && arr[i] > arr[buy]){
            cout<<"("<<buy<<" "<<i<<")"<<" ";
            buy = i+1;
            x = 0;
        }
    }
    if(x == 1)
        cout<<"No Profit";
    cout<<endl;
}