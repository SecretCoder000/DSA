#include<bits/stdc++.h>
using namespace std;
int minDist(int arr[],int n,int x,int y){
    int a,b,max;
    a=b=INT_MIN;
    max = -1;
    for(int i =0;i<n;i++){
        if(arr[i] == x)
            a = i;
        if(max != -1)
            max = abs(a-b)<max?abs(a-b):max;
        if(arr[i] == y)
            b = i;
        if(max != -1)
            max = abs(a-b)<max?abs(a-b):max;
        if(a != INT_MIN && b != INT_MIN && max == -1)
            max = abs(a-b);
    }
    return max;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int x,y;
    cin>>x>>y;
    cout<<minDist(arr,n,x,y);
    return 0;
}