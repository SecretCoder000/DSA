int Solution::maxArr(vector<int> &a) {
    int n = a.size();
    vector<int> temp = a;
    for(int i =0;i<n;i++)
        temp[i] +=i;
    sort(temp.begin(),temp.end());
    int max1 = temp[n-1]-temp[0];
    for(int i =0;i<n;i++)
        temp[i] = -a[i]+i;
    sort(temp.begin(),temp.end());
    int max2 = temp[n-1]-temp[0];
    return max(max1,max2);
}
