int findPlatform(vector<int> arr, vector<int> dep, int n){
    priority_queue<int,vector<int>,greater<>> temp;
    temp.push(0);
    vector<pair<int,int>> ad;
    for(int i =0;i<n;i++)
        ad.push_back({arr[i],dep[i]});
    sort(ad.begin(),ad.end());
    int ans = 1;
    for(int i =0;i<n;i++){
        int arrival = ad[i].first;
        int departure = ad[i].second;
        if(temp.top() < arrival){
            temp.pop();
            temp.push(departure);
        }else
            temp.push(departure);
        int size = temp.size();
        ans = max(ans,size);
    }
    return ans;
}