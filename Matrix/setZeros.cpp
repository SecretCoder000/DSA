#include<bits/stdc++.h>
#include "LinkedList/linkedlist.h"
using namespace std;
void setZeroes(vector<vector<int>>& m) {
    set<pair<int,int>> temp;
    for(int i =0;i<m.size();i++){
        for(int j =0;j<m[0].size();j++){
            if(m[i][j] == 0)
                temp.insert({i,j});
        }
    }
    for(auto itr = temp.begin();itr != temp.end();itr++){
        int r = itr->first;
        int c = itr->second;
        for(int i =0;i<m[0].size();i++){
            m[r][i] = 0;
        }
        for(int i =0;i<m.size();i++){
            m[i][c] = 0;
        }
    }
}