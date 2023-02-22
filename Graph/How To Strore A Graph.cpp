int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n+1,vector<int> (n+1,0));
    for(int i =1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mat[u][v] = mat[v][u] = 1;
    }
    return 0;
}
//OR Adjecancy List
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> mat[n+1];
    for(int i =1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mat[u].push_back(v);
        mat[v].push_back(u);
    }
    return 0;
}
//For Directed Graph
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> mat[n+1];
    for(int i =1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mat[u].push_back(v);
     }
    return 0;
}