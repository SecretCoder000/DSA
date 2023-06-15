vector <int> search(string p, string t){
    int n = t.size();
    int m = p.size();
    int i,j;
    int sum = 0;
    int hash = 0;
    for(int i =0;i<m;i++)
        hash += (p[i]-'a'+1);
    i=j=0;
    vector<int> ans;
    while(j<n){
        sum += (t[j]-'a'+1);
        if(j>= m-1){
            if(sum == hash && t.substr(i,m) == p){
                ans.push_back(i+1);
            }
            sum -= (t[i]-'a'+1);
            i++;
        }
        j++;
    }
    if(ans.empty())
        return {-1};
    return ans;
}