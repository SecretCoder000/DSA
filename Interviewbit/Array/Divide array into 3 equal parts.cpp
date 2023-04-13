int Solution::solve(int n, vector<int> &a) {
    int sum = 0;
    for(auto it : a)
        sum += it;
    if(sum%3 != 0)
        return 0;
    sum /= 3;
    vector<int> prefix,suffix;
    int temp = 0;
    for(int i =0;i<n;i++){
        temp += a[i];
        if(temp == sum)
            prefix.push_back(i);
    }
    temp = 0;
    for(int i =n-1;i>-1;i--){
        temp += a[i];
        if(temp == sum)
            suffix.push_back(i);
    }
    vector<int> prefixSum(n,0);
    prefixSum[0] = a[0];
    for(int i =1;i<n;i++)
        prefixSum[i] = prefixSum[i-1]+a[i];
    int count = 0;
    for(auto start : prefix ){
        for(auto end : suffix){
            if(start >= end || start+1==end)
                continue;
            int temp = prefixSum[end-1]-prefixSum[start];
            if(temp == sum)
                count++;
        }
    }
    return count;
}
