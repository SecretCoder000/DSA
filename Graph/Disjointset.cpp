#include <bits/stdc++.h>
using namespace std;
class Disjoint {
    vector<int> rank,parent,size;
public:
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i =0;i<=n;i++)
            parent[i] = i;
    }
    int findParent(int u){
        if(u == parent[u])
            return u;
        else
            return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v)
            return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main(){
    Disjoint d(7);
    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);
    if(d.findParent(3) == d.findParent(7))
        cout<<"Same"<<endl;
    else
        cout<<"Not Same"<<endl;

    d.unionBySize(3,7);

    if(d.findParent(3) == d.findParent(7))
        cout<<"Same"<<endl;
    else
        cout<<"Not Same"<<endl;
    return 0;
}