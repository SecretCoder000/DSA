int countSubarray(int n, vector<int>& arr, int target) {
    for(int i =0;i<n;i++) {
        if(arr[i]%2==0)
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    map<int,int> temp;
    int j,sum;
    j=sum=0;
    int ans =0;
    while(j<n){
        sum += arr[j];
        if(sum == target)
            ans++;
        if(temp.find(sum-target) != temp.end())
            ans += temp[sum-target];
        if(temp.find(sum) != temp.end())
            temp[sum]++;
        else
            temp.insert({sum,1});
        j++;
    }
    return ans;
}