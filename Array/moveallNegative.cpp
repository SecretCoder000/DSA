#include<bits/stdc++.h>
using namespace std;

void moveNegative(int arr[],int n){
    int l = 0;
        int h = n-1;
        int temp[n];
        int i =0;
        while(i<n){
            if(arr[i] >= 0)
                temp[l++] = arr[i];
            else 
                temp[h--] = arr[i];
            i++;
        }
        reverse(temp+h+1,temp+n);
        for(i =0;i<n;i++)
            arr[i] = temp[i];
}