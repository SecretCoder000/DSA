#include<bits/stdc++.h>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
    map<int,int> temp;
    int mx = INT_MIN;
    for(int i =0;i<nums.size();i++){
        auto itr = temp.find(nums[i]);
        if(itr == temp.end()){
            temp.insert({nums[i],1});
        }
        else {
            itr->second++;
            mx = mx>itr->second?mx:itr->second;
        }
    }
    if(mx == INT_MIN)
        return 1;
    map<int,pair<int,int>> res;
    int ans = INT_MAX;
    for(int i =0;i<nums.size();i++){
        auto itr = temp.find(nums[i]);
        if(itr->second == mx){
            auto itr2 = res.find(nums[i]);
            if(itr2 == res.end()){
                res.insert({nums[i],{i,INT_MIN}});
            }else {
                itr2->second.second =i;
            }
        }
    }
    for(auto itr = res.begin();itr != res.end();itr++){
        int diff = itr->second.second-itr->second.first+1;
        ans = ans>diff?diff:ans;
    }
    return ans;
}
