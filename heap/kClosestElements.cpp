#include<bits/stdc++.h>
using namespace std;
vector<int> kClosest(vector<int> arr,int x,int k){
    priority_queue<pair<int,int>> temp;
    for(int i =0;i<arr.size();i++){
        if(x == arr[i])
            continue;
        pair<int,int> temp1 = {abs(arr[i]-x),arr[i]};
        if(!temp.empty() && temp.top().first == abs(arr[i]-x) && temp.top().second > arr[i]){
            pair<int,int> temp2 = temp.top();
            temp.pop();
            temp.push(temp1);
            temp.push(temp2);
        }else 
            temp.push(temp1);
        if(temp.size()>k)
            temp.pop();
    }
    vector<int> ans;
    while(!temp.empty()){
        ans.insert(ans.begin(),temp.top().second);
        temp.pop();
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<arr.size();i++)
        cin>>arr[i];
    int k,x;
    cin>>x>>k;
    vector<int> ans = kClosest(arr,x,k);
    for(int i =0;i<ans.size();i++)
        cout<<ans[i]<<"\t";
    return 0;
}