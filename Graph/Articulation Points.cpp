class Solution {
private:
    int timer = 1;
public:
    void graphDSF(int node,int parent,vector<int> adj[],vector<int> & vis,vector<int> & step,vector<int> &low,set<int> & ans){
        vis[node] = 1;
        step[node] = timer+1;
        low[node] = timer+1;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                graphDSF(it,node,adj,vis,step,low,ans);
                low[node] = min(low[node],low[it]);
                if(low[it] >= step[node] && parent != -1)
                    ans.insert(node);
            }else if(step[it] < low[node]) {
                low[node] = step[it];
            }
        }

    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> step(V,0),low(V,0);
        vector<int> vis(V,0);
        set<int> ans;
        if(adj[0].size() > 1)
            ans.insert(0);
        graphDSF(0,-1,adj,vis,step,low,ans);
        if(ans.empty())
            return {-1};
        return vector<int> {ans.begin(),ans.end()};
    }
};