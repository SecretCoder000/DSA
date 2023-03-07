class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1)
            return -1;
        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1,m-1};
        if(source == destination)
            return 1;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
        que.push({1,source});
        vis[source.first][source.second] = 0;
        int min = INT_MAX;
        while (!que.empty()){
            int dist = que.top().first;
            auto node = que.top().second;
            que.pop();
            vector<int> temp = {-1,0,1};
            for(int i =0;i<3;i++){
                for(int j =0;j<3;j++){
                    int row = node.first+temp[i];
                    int col = node.second+temp[j];
                    if((row == node.first && col == node.second ) || row < 0 || row >= n || col < 0 || col >= m)
                        continue;
                    if(grid[row][col] == 1)
                        continue;
                    if(row == destination.first && col == destination.second && min > dist+1){
                        min = dist+1;
                        continue;
                    }
                    if(vis[row][col] == -1){
                        que.push({dist+1,{row,col}});
                        vis[row][col] = dist+1;
                    }else if(vis[row][col] > dist+1){
                        vis[row][col] = dist+1;
                    }
                }
            }
        }
        return min==INT_MAX?-1:min;
    }