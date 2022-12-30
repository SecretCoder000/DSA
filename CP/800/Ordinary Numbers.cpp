int solve(int n){
    if(n<10)
        return n;
    else {
        int temp =  n;
        int unit = 0;
        int count = 0;
        while (temp > 0){
            unit = unit*10+1;
            temp /= 10;
            count++;
        }
        return n/unit+(count-1)*9;
    }
}

