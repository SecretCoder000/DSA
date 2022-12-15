#include<bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int diff = arr[n-1]-arr[0];
        int mi,ma;
        for(int i = 1;i<n;i++){
            if(arr[i]-k < 0) continue;
            
            ma = max(arr[n-1]-k,arr[i-1]+k);
            mi = min(arr[0]+k,arr[i]-k);
            
            diff = min(diff,ma-mi);
        }
        return diff;
    }