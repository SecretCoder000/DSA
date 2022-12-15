#include<bits/stdc++.h>
using namespace std;

 void nextPermutation(vector<int>& nums){
    int f = -1;
    int s = -1;
    for(int i =nums.size()-2;i>-1;i--){
        if(nums[i] < nums[i+1]){
            f = i;
            break;
        }
    }
    for(int i =nums.size()-1;i>-1 && f != -1;i--){
        if(nums[i] > nums[f]){
            s = i;
            break;
        }   
    }
    if(f != -1 && s != -1)
        swap(nums[f],nums[s]);
    for(int i = f+1;i<=(nums.size()+f)/2;i++){
        swap(nums[i],nums[nums.size()+f-i]);
    }
 }