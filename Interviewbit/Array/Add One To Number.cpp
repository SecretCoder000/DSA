vector<int> Solution::plusOne(vector<int> &a) {
    int n = a.size();
    int carry = 1;
    int i = n-1;
    while (carry > 0 && i > -1){
        a[i] += carry;
        carry = a[i]/10;
        a[i] %= 10;
        i--;
    }
    vector<int> ans;
    if(carry > 0){
        ans = a;
        ans.insert(ans.begin(),carry);
    }else {
        for(int i =0;i<n;i++){
            if(ans.empty() && a[i] == 0)
                continue;
            ans.push_back(a[i]);
        }
    }
    return ans ;
}
