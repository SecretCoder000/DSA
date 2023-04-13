pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int flor,celi;
    flor=INT_MIN;
    celi = INT_MAX;
    for(int i =0;i<n;i++){
        if(arr[i] == x)
            return {x,x};
        if(arr[i] < x && arr[i] > flor)
            flor = arr[i];
        else if(arr[i] > x && arr[i] < celi)
            celi = arr[i];
    }
    return {flor==INT_MIN?-1:flor,celi==INT_MAX?-1:celi};
}