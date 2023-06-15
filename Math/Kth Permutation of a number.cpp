#define ll long long
ll fact(int n){
    ll f = 1;
    while(n>1){
        f = f*n;
        n--;
    }
    return f;
}
vector<int> findPerm(int a, long b) {
    vector<int> nums;
    for(int i =1;i<=a;++i)
        nums.push_back(i);
    int i = a-1;
    vector<int> ans;
    while (i){
        ll f = fact(i);
        int index = ceil(b*1.0/f);
        ans.push_back(nums[index-1]);
        nums.erase(nums.begin()+index-1);
        b = b%f;
        if(b==0)
            b = f;
        --i;
    }
    ans.push_back(nums[0]);
    return ans;
}