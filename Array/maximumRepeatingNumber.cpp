#include<bits/stdc++.h>
using namespace std;
int maxRepeating(int *arr, int n, int k) {
	    int krr[k];
	    memset(krr,0,k);
        for(int i =0;i<k;i++)
            krr[i] = 0;
	    for(int i=0;i<n;i++)
	        krr[arr[i]]++;
	    pair<int,int> max = {-1,0};
	    for(int i =0;i<k;i++){
	        if(krr[i] > max.first){
	            max.first = krr[i];
	            max.second = i;
	        }
	        else if(krr[i] == max.first && i < max.second)
	            max.second = i;
	    }
	    return max.second;
	}
    int main() {
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++)
            cin>>arr[i];
        int k;
        cin>>k;
        cout<<maxRepeating(arr,n,k);
        return 0;
    }