#include <bits/stdc++.h>
using namespace std;

int saveFlowers(int n, vector<int> &arr, string s) {
    int i,j;
    i=j=0;
    int ans = 0;
    int sum = 0;
    int mn = INT_MAX;
    while (j < n){
        if(s[j] == '1') {
            sum += arr[j];
            mn = min(mn, arr[j]);
        }
        if(s[j] == '0' || j == n-1 ){
            if(sum > 0){
                if(i != 0 && arr[i-1] > mn){
                    sum = sum - mn+arr[i-1];
                }
                ans += sum;
            }
            sum = 0;
            mn;
            i = j+1;
        }
        j++;
    }
    return  ans;
}
bool isValid(int x,int y,int n,int m){
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
bool avoidFire(int n, int m, int x, int y, vector<vector<int>> &arr) {
    if(arr[x][y] == 1 || arr[n-1][m-1] == 1)
        return false;
    vector<vector<int>> vis(n,vector<int>(m,-1));
    priority_queue<pair<pair<int,int>,int>> fire;
    priority_queue<pair<int,int>> que;
    for(int i = 0;i < n;i++) {
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 1)
                fire.push({{i, j},0});
    }
    int level = 0;
    que.push({x,y});
    while (!que.empty()){
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while (!fire.empty() && fire.top().second  == level){
            int dist = fire.top().second;
            pair<int,int> node = fire.top().first;
            fire.pop();
            for(int i =0;i<4;i++){
                int row = node.first+dr[i];
                int col = node.second+dc[i];
                if(isValid(row,col,n,m) && arr[row][col] == 0 && vis[row][col] == -1){
                    arr[row][col] = 1;
                    vis[row][col] = 1;
                    fire.push({{row,col},dist+1});
                }
            }
        }
        level++;
        pair<int,int> node = que.top();
        que.pop();
        for(int i =0;i<4;i++){
            int row = node.first+dr[i];
            int col = node.second+dc[i];
            if(row == n-1 && col == m-1 && arr[row][col] == 0)
                return true;
            if(isValid(row,col,n,m) && arr[row][col] == 0 && vis[row][col] == -1){
                vis[row][col] = 1;
                que.push({row,col});
            }
        }
    }
    return false;
}
int main(){
    vector<int> arr = {7,2,10,8,10,1};
    cout<<saveFlowers(arr.size(),arr,"100110");
    return 0;
}