vector<int> getDistinctDifference(int N, vector<int> &A) {
    map<int,int> l,r;
    for(int i =1;i<N;i++)
        r[A[i]]++;
    vector<int> ans(N,0);
    ans[0] = -r.size();
    for(int i =1;i<N;i++){
        l[A[i-1]]++;
        r[A[i]]--;
        if(r[A[i]] == 0)
            r.erase(A[i]);
        ans[i] = l.size()-r.size();
    }
    return ans;
}