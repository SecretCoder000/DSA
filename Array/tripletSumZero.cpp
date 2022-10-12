#include<bits/stdc++.h>
using namespace std;


bool tripletSumZero(int arr[],int n){
    for(int i =0;i<n-1;i++){
        unordered_set<int> temp;
        for(int j =i+1;j<n;j++){
            auto itr = temp.find(-(arr[i]+arr[j]));
            if(itr != temp.end())
                return true;
        }
        temp.insert(arr[i]);
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cout<<tripletSumZero(arr,n);
    return 0;
}