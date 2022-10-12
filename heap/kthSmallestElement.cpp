#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> & arr,int k){
    priority_queue<int> que;
    for(int i =0;i<arr.size();i++){
        que.push(arr[i]);
         while(que.size() > k)
            que.pop();
    }
    vector<int> ans;
    return que.top();
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =1;i<=n;i++)
        cin>>arr[i];
    int k ;
    cin>>k;
    cout<<kthSmallest(arr,k);
    return 0;
}