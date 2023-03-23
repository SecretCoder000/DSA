int maxRemove(vector<vector<int>>& stones, int N) {
    int n,m;
    n=m=-1;
    for(int i =0;i<N;i++){
        n = max(n, stones[i][0]);
        m = max(m,stones[i][1]);
    }
    Disjoint ds(n+m+1);
    set<int> uniqueNode;
    for(int i =0;i<N;i++){
        int u = stones[i][0];
        int v = n+stones[i][1]+1;
        ds.unionBySize(u,v);
        uniqueNode.insert(u);
        uniqueNode.insert(v);
    }
    int count=0;
    for(auto it : uniqueNode)
        if(it == ds.findParent(it))
            count++;
    return N-count;
}