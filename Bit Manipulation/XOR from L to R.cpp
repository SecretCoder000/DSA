int xorform1ton(int n){
    if(n%4 == 0)
        return n;
    else if(n%4 == 1)
        return 1;
    else if(n%4 == 2)
        return n+1;
    else
        return 0;
}
int xorLtoR(int l,int r){
    l = xorform1ton(l-1);
    r = xorform1ton(r);
    return l^r;
}