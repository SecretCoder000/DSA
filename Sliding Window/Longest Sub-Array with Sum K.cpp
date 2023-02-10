int lenOfLongSubarr(int arr[],  int n, int k) {
    int ans = 0;
    unordered_map<int,int> temp;
    temp[0] = -1;
    int sum =0;
    for(int i =0;i<n;i++){
        sum += arr[i];

        auto itr = temp.find(sum-k);
        if(itr != temp.end())
            ans = max(ans,i-itr->second);
        if(temp.find(sum) == temp.end())
            temp.insert({sum,i});

    }
    return ans;
}
