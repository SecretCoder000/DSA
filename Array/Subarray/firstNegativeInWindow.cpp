#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> printFirstNegativeInteger(ll arr[],ll n,ll k) {
    queue<ll> que;
    vector<ll> ans;
    for(ll i =0;i<n;i++){
        if(arr[i] < 0)
            que.push(i);
        if(i+1>= k){
            if(!que.empty() && que.front()<= i && que.front() >= i-k+1) {
                ans.push_back(arr[que.front()]);
                if(que.front() == i-k+1)
                    que.pop();
            }else
                ans.push_back(0);
        }
    }
    return ans;
}