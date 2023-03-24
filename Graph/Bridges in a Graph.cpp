class Solution {
private:
    int timer = 1;
public:
    void graphDSF(int node,int parent,vector<vector<int>> &adj,vector<int> & vis,vector<int> & step,vector<int> &low,vector<vector<int>> & ans){
        vis[node] = 1;
        step[node] = timer+1;
        low[node] = timer+1;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                graphDSF(it,node,adj,vis,step,low,ans);
                low[node] = min(low[node],low[it]);
                if(step[node] < low[it])
                    ans.push_back({node,it});
            }else if(low[it] < low[node]) {
                low[node] = low[it];
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj (n);
        for(int i =0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> step(n,0),low(n,0);
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        graphDSF(0,-1,adj,vis,step,low,ans);
        return ans;
    }
};