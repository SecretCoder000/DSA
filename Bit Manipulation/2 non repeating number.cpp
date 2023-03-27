bool checkBitSet(int n ,int i) {
    return n&(1<<i);
}
vector<int> singleNumber(vector<int> nums) {
    int myxor = 0;
    for(auto it : nums)
        myxor = myxor ^ it;
    int i = 0;
    while (myxor > 0){
        if(myxor&1){
            break;
        }
        myxor = myxor>>1;
        i++;
    }
    int a,b;
    a=b=0;
    for(auto it : nums){
        if(checkBitSet(it,i))
            a ^= it;
        else
            b ^= it;
    }
    if(a<b)
        return {a,b};
    else
        return {b,a};
}