#include "bits/stdc++.h"
using namespace std;
int solve(vector<int> &a) {
    int n = a.size();
    pair<int,int> left,right;
    right = {0,0};
    for(int i =0;i<n;i++){
        if(i&1)
            right.second += a[i];
        else
            right.first += a[i];
    }
    left= {0,0};
    int count = 0;
    for(int i =0;i<n;i++){
        if(i&1){
            right.second -= a[i];
        }else {
            right.first -= a[i];
        }
        if(left.first +right.second == left.second+right.first)
            count++;
        if(i&1){
            left.second += a[i];
        }else {
            left.first += a[i];
        }
    }
    return count;
}




int main(){
    //cout<<beautySum("geeksforgeeks");
    vector<int> arr  = { 2, 8, 2, 2, 6, 3 };
    cout<<solve(arr);
    return 0;
}