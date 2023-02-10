int largest(vector<int> &arr, int n){
    int max = INT_MIN;
    int i =0,j = n-1;
    while(i<=j){
        max = max<arr[i]?arr[i]:max;
        max = max<arr[j]?arr[j]:max;
        i++;
        j--;
    }
    return max;
}