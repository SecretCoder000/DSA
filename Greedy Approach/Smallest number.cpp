string smallestNumber(int s, int d){
    if(s > d*9)
        return "-1";
    d--;
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    int i = 10;
    string str;
    while(s > 0 && d > 0){
        if(arr[i] < s){
            str.push_back(arr[i]+48);
            d--;
            s -= arr[i];
        }else
            i--;
    }
    if(s<0 || s>9)
        return "-1";
    if(d == 0){
        str.push_back(s+48);
    }
    reverse(str.begin(),str.end());
    return str;
}