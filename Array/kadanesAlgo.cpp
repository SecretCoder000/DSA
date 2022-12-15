#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n){
        long long sum = INT_MIN;
        long long temp = 0;
        int i =0;
        while(i<n){
            temp += arr[i];
            sum = sum<temp?temp:sum;
            if(temp < 0)
                temp = 0;
            i++;
        }
        return sum==0?-1:sum;
    }