vector<int> flip(string a) {
    int z,o;
    pair<int,pair<int,int>> ans= {0,{-1,-1}};
    int n = a.size();
    int j ;
    z=o=j=0;
    for(int i =0;i<n;i++){
        if(a[i] == '0')
            z++;
        else
            o++;
        if((z-o) > ans.first){
            ans.first = z-o;
            ans.second = {j,i};
        }else if(z-o < 0){
            j=i+1;
            z=o=0;
        }
    }
    if(ans.first == 0)
        return  {};
    return {ans.second.first+1,ans.second.second+1};
}