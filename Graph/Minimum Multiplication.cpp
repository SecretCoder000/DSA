int minimumMultiplications(vector<int>& arr, int start, int end) {
    vector<int> vis(9999,INT_MAX);
    queue<pair<int,int>> que;
    que.push({0,start});
    vis[start] = 0;
    while (!que.empty()){
        int num = que.front().second;
        int step = que.front().first;
        que.pop();
        for(int i =0;i<arr.size();i++){
            int temp = (num*arr[i])%100000;
            if(temp == end)
                return step+1;
            que.push({step+1,temp});
        }
    }
    return -1;
}