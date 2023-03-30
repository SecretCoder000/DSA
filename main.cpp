#include <bits/stdc++.h>
using namespace std;
vector<int> minPartition(int rs){
    vector<int> coins = {2000,500,200,100,50,20,10,5,2,1};
    int n = coins.size();
    vector<int> ans ;
    for(int i =0;i<n && rs > 0;i++){
        if(coins[i] <= rs){
            int times = rs/coins[i];
            rs = rs%coins[i];
            vector<int> temp(coins[i],times);
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{4,20},{1,10},{1,40}, {1,30}};
    minPartition(43);
    return 0;
}