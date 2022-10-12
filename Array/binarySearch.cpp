#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr,int key){
    int lo = 0;
    int hi = arr.size()-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(key<arr[mid])
            hi = mid-1;
        else if(key > arr[mid])
            lo = mid+1;
        else    
            return mid;
    }
    return -1;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<binarySearch(arr,k);
    return 0;
}