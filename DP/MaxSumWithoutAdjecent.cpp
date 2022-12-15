int findMaxSum(int *arr, int n) {
    int max = arr[0];
    for(int i = 2;i<n;i++){
        arr[i] +=max;
        max = max<arr[i-1]?arr[i-1]:max;
    }
    return max>arr[n-1]?max:arr[n-1];
}
