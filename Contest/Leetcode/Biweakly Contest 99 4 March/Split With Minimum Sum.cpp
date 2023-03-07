int splitNum(int num) {
    vector<int> arr;
    while(num>0){
        int r = num%10;
        num /= 10;
        arr.push_back(r);
    }
    sort(arr.begin(),arr.end());
    int sum1,sum2;
    sum1=sum2=0;
    for(int i=0;i<arr.size();i++){
        if(i%2==0)
            sum1 = sum1*10+arr[i];
        else
            sum2 = sum2*10+arr[i];
    }
    return sum1+sum2;
}