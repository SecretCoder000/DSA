#include<bits/stdc++.h>
using namespace std;
void merge(long long arr1[], long long arr2[], int n, int m) { 
    int sum = n+m;
    sum = sum/2 + sum%2;
    while(sum > 0){
        int l = 0;
        int r = sum;
        while(l<n && r<n){
            if(arr1[l] > arr1[r])
                swap(arr1[l],arr1[r]);
            l++;
            r++;
        }
        while(l<n && r < n+m ){
            if(arr1[l] > arr2[r-n])
                swap(arr1[l],arr2[r-n]);
            l++;
            r++;
        }
        while(l >= n && r < n+m){
            if(arr2[l-n] > arr2[r-n])
                swap(arr2[l-n],arr2[r-n]);
            l++;
            r++;
        }
        if (sum<=1)
            sum = 0;
        else 
            sum = sum/2 + sum%2;
    }    
}
int main(){
    vector<long long> arr= {1 ,3, 5, 7};
    vector<long long> brr= {0 ,2 ,6 ,8 ,9};
    merge(arr.data(),brr.data(),arr.size(),brr.size());
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    for(int i =0;i<brr.size();i++)
        cout<<brr[i]<<"\t";
    return 0;
}