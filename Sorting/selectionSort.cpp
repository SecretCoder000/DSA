#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int min=INT_MAX,index=-1;
        for(int j =i;j<n;j++){
            if(min > arr[j]){
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    selectionSort(arr,n);
    cout<<"After Sorting : ";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}