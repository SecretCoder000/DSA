#include<bits/stdc++.h>
using namespace std;
int firstNonRepeating(int arr[],int n){
    map<int,pair<int,int>> temp;
    for(int i =0;i<n;i++){
        auto itr = temp.find(arr[i]);
        if(itr == temp.end()) 
            temp.insert({arr[i],{i,1}});
        else 
            itr->second.second++;
    }
    int min = INT_MAX;
    for(auto itr = temp.begin();itr != temp.end();itr++)
        if(itr->second.second == 1 && min > itr->second.first)
            min = itr->second.first;
    if(min == INT_MAX)
        return 0;
    return arr[min];
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cout<<firstNonRepeating(arr,n);
    return 0;
}