#include<bits/stdc++.h>
using namespace std;
int smallestSubWithSum(int arr[],int n,int x){
    int mi=INT_MAX;
    int i,j,s;
    i=j=s=0;
    while(i<=j && j < n){
        while(s<=x && j < n){
            s += arr[j];
            j++;
        }
        while (s>x && i<j){
            mi = min(mi,j-i);
            s -= arr[i];
            i++;
        }
    }
    return mi;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<smallestSubWithSum(arr,n,k);
    return 0;
}