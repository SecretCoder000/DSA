#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.empty())
        return 0;
    map<int,int> temp ;
    for(int i =0;i<nums.size();i++)
        temp.insert({nums[i], 1});
    int max = INT_MIN;
    for(auto itr = temp.begin();itr != temp.end();itr++){
        auto itr2 = temp.find(itr->first+1);
        if(itr2 != temp.end()){
            itr2->second = itr->second+1;
        }else {
            max = max<itr->second?itr->second:max;
        }
    }
    if(max == INT_MIN)
        max = temp.size();
    return max;
}