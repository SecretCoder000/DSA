int numberOfSubarrayWithAtMostKInterget(vector<int> arr,int k){
    int i,j,ans;
    i=j=ans=0;
    int count = 0;
    vector<int> temp(arr.size()+1,0);
    while(j<arr.size()){
        if(temp[arr[j]] == 0)
            count++;
        temp[arr[j]]++;
        while(count > k){
            temp[arr[i]]--;
            if(temp[arr[i]] == 0)
                count--;
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    return ans;
}
int subarrayCount(vector<int> &s, int n, int k) {
    int i = numberOfSubarrayWithAtMostKInterget(s,k);
    int j = numberOfSubarrayWithAtMostKInterget(s,k-1);
    return i-j;
}