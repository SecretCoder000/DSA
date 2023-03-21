#include <bits/stdc++.h>
#include "./Graph/Disjoint.h"
using namespace std;

string toBinary(int n){
    string str;
    while (n>0){
        str.push_back(n%2+48);
        n /= 2;
    }
    return str;
}
vector<long long int> xorPairs(int N, vector<int> &A1, vector<int> &A2, int Q, vector<vector<int>> &query) {
    vector<long long> ans;
    map<int,string> coord;

    for(int i =0;i<query.size();i++){
        int k = query[i][0];
        int l1 = query[i][1]-1;
        int r1 = query[i][2]-1;
        int l2 = query[i][3]-1;
        int r2 = query[i][4]-1;
        long long count = 0;
        for(int a = l1;a<=r1;a++){
            for(int b = l2;b<=r2;b++){
                int temp = A1[a]^A2[b];
                int shift = temp>>(k-1);
                if(shift%2 == 1)
                    count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}
int main(){
    vector<int> arr = {3};
    vector<int> brr = {1};
    vector<vector<int>> query = {{2, 1, 1, 1, 1}};
    vector<long long> ans = xorPairs(arr.size(),arr,brr,query.size(),query);
    for(int i =0;i<ans.size();i++)
        cout<<ans[i]<<"\t";
    //cout<<(13>>1);
    return 0;
}