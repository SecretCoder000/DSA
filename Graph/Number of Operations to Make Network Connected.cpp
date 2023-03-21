#include "Disjoint.h"

int Solve(int n, vector<vector<int>>& edge) {
    Disjoint ds(n);
    int cycle = 0;
    for(int i =0;i<edge.size();i++) {
        if (ds.findParent(edge[i][0]) == ds.findParent(edge[i][1]))
            cycle++;
        else
            ds.unionByRank(edge[i][0], edge[i][1]);
    }
    int count = 0;
    for(int i =0;i<n;i++){
        if(ds.findParent(i) == i)
            count++;
    }
    if(count-1 > cycle)
        return -1;
    else
        return count-1;
}