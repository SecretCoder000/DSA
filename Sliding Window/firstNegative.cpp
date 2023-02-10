vector<ll> printFirstNegativeInteger(ll arr[],ll n, ll k) {
    vector<ll> ans;
    queue<ll> que;
    for(ll i =0;i<k-1;i++) {
        if (arr[i] < 0)
            que.push(i);
    }
    for(int i = k-1;i<n;i++){
        if(arr[i] < 0)
            que.push(i);
        if(que.front() < i-k+1)
            que.pop();
        if(que.empty())
            ans.push_back(0);
        else
            ans.push_back(que.front());
    }
    return ans;
}