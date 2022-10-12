#include<bits/stdc++.h>
using namespace std;
vector<int> frequencySort(vector<int> arr){
    vector<int> ans;
    map<int,int> temp;
    for(int i=0;i<arr.size();i++){
        auto itr = temp.find(arr[i]);
        if(itr == temp.end())
            temp.insert({arr[i],1});
        else
            itr->second++; 
    }
    priority_queue<pair<int,int>> que;
    for(auto itr = temp.begin();itr != temp.end();itr++)
        que.push({itr->second,itr->first});
    while(!que.empty()){
        pair<int,int> op = que.top();
        que.pop();
        if(!que.empty() && que.top().first == op.first && que.top().second < op.second){
            pair<int,int> op2 = que.top();
            que.pop();
            ans.push_back(op2.second);
            que.push(op);
        }else 
            ans.push_back(op.second);
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i =0;i<arr.size();i++)
            cin>>arr[i];
        vector<int> ans= frequencySort(arr);
        for(int i =0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}