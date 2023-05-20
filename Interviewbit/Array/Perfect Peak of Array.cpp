int Solution::perfectPeak(vector<int> &a) {
    set<int> candidate;
    int n = a.size();
    int mx = a[0];
    for(int i =1;i<n;i++)
        if(a[i] > mx){
            candidate.insert(i);
            mx = a[i];
        }
    mx = a[n-1];
    for(int i = n-2;i>-1;i--){
        if(a[i] < mx ){
            if(candidate.find(i) != candidate.end())
                return 1;
            mx = a[i];
        }
    }
    return 0;
}