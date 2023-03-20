#include <bits/stdc++.h>
using namespace std;

vector<int> pascleTriangleRow(int row){
    //Rule for pascle is n-1Cr-1;
    vector<int> ans(row,0);
    int n = row-1;
    int r = 1;
    int prev = 1;
    for(int i =0;i<(row+1)/2;i++){
        ans[i]=ans[row-1-i]=prev;
        prev = prev*n/r;
        n--;
        r++;
    }
    return ans;
}

int main(){
    vector<int> row = pascleTriangleRow(6);
    for(auto it : row)
        cout<<it<<"\t";
    cout<<endl;

    return 0;
}