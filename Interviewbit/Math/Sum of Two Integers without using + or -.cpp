int getSum(int a, int b) {
    int carry=b==0?a:b;
    int sum = 0;
    bool flag = false;
    if(a<0 && b < 0){
        a = -a;
        b = -b;
        flag=true;
    }
    while(carry != 0){
        sum = a^b;
        carry = a&b;
        if(carry == INT_MIN)
            carry = 0;
        else
            carry = carry<<1;
        a = sum;
        b = carry;
    }
    return flag?-sum:sum;
}