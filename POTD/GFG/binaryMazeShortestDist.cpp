#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> s,pair<int, int> d) {
    if(s == d)
        return 0;
    queue<pair<int,pair<int,int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n,vector<int> (m,INT_MAX));
    q.push({0,s});
    ans[s.first][s.second] = 0;
    int dr[] = {0,-1,0,1};
    int dc[] = {-1,0,1,0};
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        for(int i =0;i<4;i++){
            int newR = r+dr[i];
            int newC = c+dc[i];
            if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1 && dist+1 < ans[newR][newC]){
                ans[newR][newC] = dist+1;
                if(newR == d.first && newC == d.second)
                    return dist+1;
                q.push({dist+1,{newR,newC}});
            }
        }
    }
    return -1;
}