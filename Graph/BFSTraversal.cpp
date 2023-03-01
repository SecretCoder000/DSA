vector<int> graphBSF(int n, vector <vector<int>> adj, int start) {
    vector<int> visited(n + 1);
    queue<int> que;
    vector<int> bsf;
    que.push(start);
    visited[start] = 1;
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        bsf.push_back(node);
        for (auto adjNode: adj[node]) {
            if (visited[adjNode] == 0) {
                visited[adjNode] = 1;
                que.push(adjNode);
            }
        }
    }
    return bsf;
}