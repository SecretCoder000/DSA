#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> &arr ,int k){
    int lo =0;
    int hi = arr.size()-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid] == k)
            return true;
        else if(arr[mid] > k)
            hi = mid-1;
        else
            lo = mid +1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& mat, int k) {
    for(int i =0;i<mat.size();i++){
        if(k >= mat[i][0] && k <= mat[i][mat[i].size()-1]){
            return binarySearch(mat[i],k);
        }
    }
    return false;
}

