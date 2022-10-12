#include<bits/stdc++.h>
using namespace std;
void reverseArrayInGroup(int arr[],int n,int k){
    k %= n;
    for(int i =0;i<n;i+= k){
        if(i+k>n)
            k = n-i;
        int temp = k/2;
        int l = i;
        int r = i+k-1;
        while(temp--)
            swap(arr[l++],arr[r--]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    reverseArrayInGroup(arr,n,k);
    cout<<"After Reverse By K : ";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    return 0;
}