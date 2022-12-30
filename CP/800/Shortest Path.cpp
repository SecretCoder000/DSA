bool inBetween(int a,int b,int c){
    if(c >= a && c <= b || c>=b && c<=a)
        return true;
    return false;
}

int solve(pair<int,int> a,pair<int,int> b,pair<int,int> f){
    int res = abs(a.first-b.first)+abs(a.second-b.second);
    if((a.first == b.first && b.first == f.first && inBetween(a.second,b.second,f.second)) || (a.second == b.second && b.second == f.second && inBetween(a.first,b.first,f.first)))
        res += 2;
    return res;
}