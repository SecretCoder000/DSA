#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[],int n){
    int l,m,h;
    l=m=0;
    h = n-1;
    while(m<=h){
        if(arr[m] == 0)
            swap(arr[l++],arr[m++]);
        else if(arr[m] == 1)
            m++;
        else 
            swap(arr[h--],arr[m]);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    sort012(arr,n);
    cout<<"After Sorting Array is : ";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}