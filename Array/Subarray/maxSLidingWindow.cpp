#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> ans;
    multiset<int,greater<int>> temp;
    for(int i =0;i<n;i++){
        temp.insert(arr[i]);
        if(i+1>=k){
            auto itr = temp.begin();
            ans.push_back(*itr);
            temp.erase(temp.find(arr[i-k+1]));
        }
    }
    return ans;
}