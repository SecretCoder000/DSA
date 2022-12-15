#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n){
    int l = 0;
    int count = 0;
    int max = 0;
    for(int i =0;i<=max;){
        if(i == max)
            count++;
        pair<int,int> temp = {INT_MIN,-1};
        
        for(int j = i+1;j<=i+arr[i];j++){
            if(j == n-1 || j > n-1)
                return count+1;
            if(temp.first < arr[j]){
                temp.first = arr[j];
                temp.second = j;
            }
        }
        count++;
        i = temp.second;
    }
    return count;
}
int main(){
    int arr[] = {1, 4, 3, 2, 6, 7};
    cout<<minJumps(arr,6);
    return 0;
}