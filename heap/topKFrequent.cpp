#include<bits/stdc++.h>
using namespace std;
vector<int> topK(vector<int>& nums, int k) {
        map<int,int> temp;
        for(int i =0;i<nums.size();i++){
            auto itr = temp.find(nums[i]);
            if(itr == temp.end())
                temp.insert({nums[i],1});
            else 
                itr->second++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> temp2;
        for(auto itr = temp.begin();itr != temp.end();itr++){
            temp2.push({itr->second,itr->first});
            if(temp2.size()>k)
                temp2.pop();
        }
        vector<int> ans;
        while(!temp2.empty()){
            pair<int,int> op = temp2.top();
            temp2.pop();
            if(!temp2.empty() && op.first == temp2.top().first && op.second > temp2.top().second){
                pair<int,int> op2 = temp2.top();
                temp2.pop();
                ans.insert(ans.begin(),op2.second);
                temp2.push(op);
            }else{
                ans.insert(ans.begin(),op.second);
            }
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<arr.size();i++)
        cin>>arr[i];
    int k;
    cin>>k;
    vector<int> ans= topK(arr,k);
    for(int i =0;i<ans.size();i++)
        cout<<ans[i]<<"\t";
    return 0;
}