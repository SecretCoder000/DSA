vector<int> Solution::addArrays(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int n = a.size() ;
    int m = b.size();
    int i,j;
    i=n-1;
    j=m-1;
    int carry = 0;
    while(i>-1 && j>-1){
        int sum = a[i]+b[j]+carry;
        ans.push_back(sum%10);
        carry = sum/10;
        i--;
        j--;
    }
    while(i>-1){
        int sum = a[i]+carry;
        ans.push_back(sum%10);
        carry = sum/10;
        i--;
    }
    while(j>-1){
        int sum = b[j]+carry;
        ans.push_back(sum%10);
        carry = sum/10;
        j--;
    }
    while(carry>0){
        ans.push_back(carry%10);
        carry /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
