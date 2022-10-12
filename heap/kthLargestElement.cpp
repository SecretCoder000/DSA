#include<bits/stdc++.h>
using namespace std;
vector<int> kLargest(vector<int> & arr,int k){
    priority_queue<int,vector<int>,greater<int>> que;
    for(int i =0;i<arr.size();i++){
        que.push(arr[i]);
         while(que.size() > k)
            que.pop();
    }
    vector<int> ans;
    while(!que.empty()){
        ans.insert(ans.begin(),que.top());
        que.pop();
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =1;i<=n;i++)
        cin>>arr[i];
    int k ;
    cin>>k;
    vector<int> temp = kLargest(arr,k);
    cout<<"K Largest Elements : ";
    for(int i =0;i<temp.size();i++)
        cout<<temp[i]<<"\t";
    return 0;
}