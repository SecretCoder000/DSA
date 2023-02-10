bool check(vector<int>& arr) {
    int ind = -1;
    for(int i =1;i<arr.size();i++){
        if(arr[i] < arr[i-1]){
            ind = i;
            break;
        }
    }
    if(ind == -1)
        return true;
    int n = arr.size();
    for(int i = ind+1;i<n+ind;i++){
        if(arr[i%n] < arr[(i-1)%n])
            return false;
    }
    return true;
}