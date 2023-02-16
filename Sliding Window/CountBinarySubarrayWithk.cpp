int numberOfSubarrays(vector<int>& arr, int n, int target){
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