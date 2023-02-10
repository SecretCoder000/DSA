int print2largest(int arr[], int n) {
    int f,s;
    f=s=INT_MIN;
    for(int i =0;i<n;i++){
        if(arr[i] > f){
            s = f;
            f = arr[i];
        }else if(arr[i] > s && arr[i] != f)
            s = arr[i];
    }
    return s%INT_MAX;
}