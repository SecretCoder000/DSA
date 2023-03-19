int distMoney(int money, int children) {
    money -= children;
    if(money < 0)
        return -1;
    int cnt_7 = money/7;
    int val_other = money%7;
    if(cnt_7 < children){
        int rem = children-cnt_7;
        if(rem == 1 && val_other == 3)
            return max(0,cnt_7-1);
        else
            return cnt_7;
    }
    if(cnt_7 > children)
        return cnt_7-1;
    else {
        if(val_other == 0)
            return cnt_7;
        else
            return cnt_7-1;
    }
}