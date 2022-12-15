#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > stockBuySell(vector<int> arr, int n){
    int mini = -1;
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        if(i == n-1) {
            if(mini != -1)
                ans.push_back({mini,i});
            continue;
        }
        if(mini == -1 && arr[i]<arr[i+1])
            mini = i;
        if(mini != -1 && arr[i] > arr[i+1]){
            ans.push_back({mini,i});
            mini = -1;
        }
    }
    return ans;
}
