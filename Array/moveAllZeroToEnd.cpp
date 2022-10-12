#include<bits/stdc++.h>
using namespace std;
/*1st */
void moveAllZeroToEnd(int arr[],int n){
        int z = n-1;
	    for(int i = n-1;i>-1;i--){
	        if(arr[i] == 0){
	            int j = i;
	            while(j<z){
	                swap(arr[j],arr[j+1]);
	                j++;
	            }
	            z--;
	        }
	    }
}
// 2nd approach 
void pushZerosToEnd(int arr[], int n) {
	int i = 0,j=0;
    for(i;i<n;i++) {
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }
    while(j<n)  
        arr[j++] = 0;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    pushZerosToEnd(arr,n);
    cout<<"Now Array  : ";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}