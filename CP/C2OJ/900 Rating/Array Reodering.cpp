#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> arr){
    int c = 0;
    int ans = 0;
    vector<int> res;
    for(int k =0;k<arr.size();k++){
        if(arr[k]%2 == 0) {
            res.insert(res.begin(),arr[k]);
            ans += (arr.size()-1-c);
            c++;
        }
        else
            res.push_back(arr[k]);
    }
    for(int k = c;k<res.size();k++){
        for(int i = k+1;i<res.size();i++)
            if(__gcd(res[i],res[k]) > 1)
                ans++;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i =0;i<n;i++)
            cin>>arr[i];
        cout<<solve(arr)<<endl;
    }
    return 0;
}