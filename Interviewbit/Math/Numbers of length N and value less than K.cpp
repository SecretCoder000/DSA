
int solve(vector<int> &a, int b, int c) {
    if(a.empty())
        return 0;
    int count = 0;
    vector<int> arr;
    int temp = c;
    while(c>0){
        arr.push_back(c%10);
        c /= 10;
    }
    c = temp;
    if(b > arr.size())
        return 0;
    reverse(arr.begin(),arr.end());
    int n = arr.size();
    if(n > b){
        int ans = 0;
        if(a[0] == 0)
            ans = (a.size()-1)*pow(a.size(),b-1);
        else
            ans = pow(a.size(),b);
        if(b == 1 && a[0] == 0)
            ans++;
        return ans;
    }else {
        if(b == 1){
            for(int i =0;i<a.size();++i)
                if(a[i] < c)
                    count++;
            return count;
        }

    }
    int countSmaller = 0;
    n = a.size();
    for(int i =0;i<n;++i){
        if(a[i] == 0)
            continue;
        if(a[i] > arr[0])
            break;
        countSmaller++;
    }
    int ans = countSmaller*pow(n,b-1);;

    bool flag = false;
    int j = 0;
    for(int i =0;i<n;++i)
        if(a[i] == arr[j]){
            flag = true;
            break;
        }
    j++;
    while(flag && j < b){
        flag = false;
        int countx = 0;
        for(int i =0;i<n;++i){
            if(a[i] > arr[j])
                countx++;
            if(a[i] == arr[j])
                flag = true;
        }
        ans -= (countx*pow(n,b-1-j));
        j++;
    }
    if(b == j && flag)
        ans--;
    return ans;
}
