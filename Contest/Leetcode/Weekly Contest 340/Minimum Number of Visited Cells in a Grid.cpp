#define mytype pair<int,pair<int,int>>
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        priority_queue<mytype,vector<mytype>,greater<mytype>> que;
        int n = grid.size();
        int m = grid[0].size();
        que.push({1,{0, 0}});
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        cost[0][0]=1;
        int ans=INT_MAX;
        while (!que.empty()){
            int dist = que.top().first;
            int row = que.top().second.first;
            int col = que.top().second.second;
            if(row == n-1 && col == m-1)
                return dist;
            que.pop();
            for(int j = col+1;j<=grid[row][col]+col && j < m;j++){
                if(dist+1 < cost[row][j]){
                    que.push({dist+1,{row, j}});
                    cost[row][j] = dist+1;
                }
                if(row == n-1 && j == m-1)
                    return dist+1;
            }
            for(int j = row+1;j<=grid[row][col]+row && j < n;j++){
                if(dist+1 < cost[j][col]){
                    cost[j][col] = dist+1;
                    que.push({dist+1,{j, col}});
                }
                if(j == n-1 && col == m-1)
                    return dist+1;
            }
        }
        return -1;
    }
};