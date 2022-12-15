#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
    int f = floor(nums.size()/2);
    map<int,int> temp;
    for(int i =0;i<nums.size();i++){
        auto itr = temp.find(nums[i]);
        if(itr == temp.end())
            temp.insert({nums[i],1});
        else
            itr->second++;
    }
    for(auto itr= temp.begin();itr != temp.end();itr++){
        if(itr->second>f)
            return itr->first;
    }
    return -1;
}