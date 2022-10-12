#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int nL = m-l+1;
    int nR = r-m;
    int left[nL];
    int right[nR];
    for(int i =0;i<nL;i++)
        left[i] = arr[l+i];
    for(int i =0;i<nR;i++)
        right[i] = arr[m+1+i];
    int i,j,k;
    i=j=0;
    k=l;

    while (i < nL && j < nR){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;        
        }else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < nL){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j < nR){
        arr[k]=right[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l >= r)
        return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid); 
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r); 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"After Sorting : ";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}