int clearIthBit(int n,int i){
    int mask = ~(1<<i);
    return mask & n;
}