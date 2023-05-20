int reverse(int x) {
    bool flag = false;
    if(x == INT_MAX || x == INT_MIN)
        return 0;
    if(x < 0){
        x = -x;
        flag = true;
    }
    int r = 0;
    while(x > 0 ){
        if(r > (INT_MAX/10) || (r == (INT_MAX/10) && x%10 > INT_MAX%10))
            return 0;
        r = r*10+x%10;
        x /= 10;
    }
    return flag?-r:r;
}