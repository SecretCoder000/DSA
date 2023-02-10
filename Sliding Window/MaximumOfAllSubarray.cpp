vector<int> max_of_subarrays(int *arr, int n, int k){
    list<int> que;
    vector<int> ans;
    int i =0;
    while(i < n){
        while(!que.empty() && arr[que.back()] < arr[i])
            que.pop_back();
        que.push_back(i);
        if(i+1>=k)
            ans.push_back(arr[que.front()]);
        if(que.front() == i-k+1)
            que.pop_front();
        i++;
    }
    return ans;
}