int Solution::maxSubArray(const vector<int> &a) {
    int sum = INT_MIN;
    int temp = 0;
    int n = a.size();
    for(int i =0;i<n;i++){
        temp += a[i];
        sum = sum<temp?temp:sum;
        if(temp < 0){
            temp = 0;
        }
    }
    return sum;
}
