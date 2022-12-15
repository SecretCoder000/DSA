#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int arr[n];
        for(int i =0;i<n;i++)
            arr[i] = 0;
        for(int i =0;i<n;i++){
            arr[nums[i]-1]++;
        }
        for(int i =0;i<n;i++)
            if(arr[i] > 1)
                return i+1;
        return -1;
    }