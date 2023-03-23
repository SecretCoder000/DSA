#include <bits/stdc++.h>
using namespace std;
string toBinary(int n){
    string str;
    while (n>0){
        str.push_back(n%2);
        n /= 2;
    }
    return str;
}
vector<long long int> xorPairs(int N, vector<int> &A1, vector<int> &A2, int Q, vector<vector<int>> &query) {
    vector<long long> ans;
    map<int,string> temp;
    for(int i =0;i<N;i++){
        if(temp.find(A1[i]) == temp.end())
            temp.insert({A1[i], toBinary(A1[i])});
        if(temp.find(A2[i]) == temp.end())
            temp.insert({A2[i], toBinary(A2[i])});
    }
    for(int i =0;i<query.size();i++){
        int k = query[i][0]-1;
        int l1 = query[i][1]-1;
        int r1 = query[i][2]-1;
        int l2 = query[i][3]-1;
        int r2 = query[i][4]-1;
        long long count = 0;
        for(int a = l1;a<=r1;a++){
            for(int b = l2;b<=r2;b++){
                if(temp[A1[a]][k] != temp[A2[b]][k])
                    count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}
