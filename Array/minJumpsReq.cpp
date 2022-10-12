#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n){
    int l = 0;
    int count = 0;
    int i =0;
    //{}
    while(l < n-1){
        if(arr[l] <= 0)
            return -1;
        int temp = i;
        pair<int,int> max= {INT_MIN,-1};
        for(i;i<=l;i++){
            if(arr[i] > max.first){
                max.first = arr[i];
                max.second = i;
            }
        }
        count++;
        l = max.first+l;
        i = temp+max.second;
    }
    return count ;
}
int main(){
    // int m,n;
    // cin>>n;
    // int arr[n];
    // for(int i =0;i<n;i++)
    //     cin>>arr[i];
    int arr[] = {1, 4, 3, 2, 6, 7};
    cout<<minJumps(arr,6);
    return 0;
}