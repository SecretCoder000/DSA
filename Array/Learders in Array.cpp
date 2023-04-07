vector<int> leaders(int a[], int n){
    vector<int> rightGreater;
    int max = a[n-1];
    for(int i =n-1;i>-1;i--){
        if(a[i] >= max){
            rightGreater.push_back(a[i]);
            max = a[i];
        }
    }
    reverse(rightGreater.begin(),rightGreater.end());
    return rightGreater;
}