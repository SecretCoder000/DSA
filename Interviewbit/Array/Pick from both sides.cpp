int Solution::solve(vector<int> &arr, int b) {
    int sum = 0;
    int n = arr.size();
    for(int i =0;i<b;i++)
        sum += arr[i];
    int max = sum;
    int j = n-1;
    for(int i =b-1;i>=0;i--,j--){
        sum -= arr[i];
        sum += arr[j];
        if(sum > max)
            max = sum;
    }
    return max;
}
