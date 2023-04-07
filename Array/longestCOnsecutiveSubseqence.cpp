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

int longestConsecutive(vector<int>& nums) {
    set<int> temp;
    int n = nums.size();
    for(int i =0;i<n;i++)
        temp.insert(nums[i]);
    int max = 1;
    for(int i =0;i<n;i++){
        if(temp.find(nums[i]-1) == temp.end()){
            int count = 1;
            int node = nums[i];
            while (temp.find(node+1) != temp.end()){
                count++;
                node++;
            }
            max = max<count?count:max;
        }
    }
    return max;
}