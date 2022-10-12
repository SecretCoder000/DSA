#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> printFirstNegativeinteger(ll arr[],ll n,ll k){
    queue<ll> index;
    vector<ll> ans;
    for(ll i =0;i<n;i++)
        if(arr[i] < 0)
            index.push(i);
    for(ll i =0;i<=n-k;i++){
        if(!index.empty() && index.front() >= i && index.front()<= i+k-1){
            ans.push_back(arr[index.front()]);
            if(index.front() == i)
                index.pop();
        }
        else 
            ans.push_back(0);
    }
    return ans;
}
int main() {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i =0;i<n;i++)
        cin>>arr[i];
    ll k;
    cin>>k;
    vector<ll> ans = printFirstNegativeinteger(arr,n,k);
    for(ll i =0;i<ans.size();i++)
        cout<<ans[i]<<"\t";
    cout<<endl;
    return 0;
}