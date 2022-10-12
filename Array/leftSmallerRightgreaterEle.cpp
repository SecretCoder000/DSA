#include<bits/stdc++.h>
using namespace std;

int findElement(int arr[],int n){
    vector<int> left;
    vector<int> right;
    int max = arr[0];
    left.push_back(max);
    for(int i =1;i<n;i++){
        left.push_back(max);
        if(max < arr[i])
            max = arr[i];
    }
    max = arr[n-1];
    right.insert(right.begin(),max);
    for(int i =n-2;i>-1;i--){
        right.insert(right.begin(),max);
        if(max > arr[i])
            max = arr[i];
    }

    for(int i =0;i<n;i++){
        if(left[i] < arr[i] && arr[i] < right[i])
            return arr[i];
    }
    return -1;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cout<<findElement(arr,n);
    return 0;
}