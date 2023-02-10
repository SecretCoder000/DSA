#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool match(map<char,int> temp,map<char,int> target){
        for(auto itr = target.begin();itr != target.end();itr++){
            if(temp.find(itr->first) == temp.end())
                return false;
            else if(temp[itr->first] < itr->second)
                return false;
        }
        return true;
}
string minWindow(string s, string t) {

    map<char,int> temp;
    map<char,int> mp;
    for(int i =0;i<t.size();i++)
        temp[t[i]]++;
    int i,j;
    i=j=0;
    string ans= "";
    while(j<s.size()) {
        mp[s[j]]++;
        if (match(mp,temp)) {
            while((temp.find(s[i]) == temp.end()) || (mp[s[i]] >= temp[s[i]]) ) {
                if (temp.find(s[i]) != temp.end()) {
                    if (mp[s[i]] >= temp[s[i]])
                        mp[s[i]]--;
                    if (ans.empty())
                        ans = s.substr(i, j - i + 1);
                    else
                        ans = ans.size() > (j - i + 1) ? s.substr(i, j - i + 1) : ans;
                } else
                    mp[s[i]]--;
                if (mp[s[i]] == 0){
                    mp.erase(mp.find(s[i]));
                    if(temp.find(s[i]) != temp.end()){
                        i++;
                        break;
                    }
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}
int findMaxSubarraySum(long long arr[], int n, long long sum){
    int i,j;
    i=j=0;
    long long x = 0;
    long long ans = INT_MIN;
    while(j<n){
        x += arr[j];
        while(x>sum){
            x -= arr[i];
            i++;
        }
        if(x == sum)
            return x;
        else
            ans = max(ans,x);
        j++;
    }
    return ans;
}
int findSubString(string str){
    set<char> temp(str.begin(),str.end());
    map<char,int> mp;
    int j =0;
    int ans = INT_MAX;
    for(int i =0;i<str.size();i++){
        mp[str[i]]++;
        while (mp.size()>=temp.size()){
            mp[str[j]]--;
            if(mp[str[j]] == 0){
                ans = min(ans,i-j+1);
                mp.erase(str[j]);
            }
            j++;
        }
    }
    return ans;
}
int solve(int arr[],int l ,int e,int k,int sum,int & ans){
    if(sum%k==0)
        return e-l+1;
    if(e-l == 0)
        return 0;
    int sum2 = 0;
    int temp = 0;
    for(int i =l;i<=e;i++){
        sum2+= arr[l];
        sum -= arr[l];
        int left = solve(arr,l,i,k,sum2,ans);
        int right = solve(arr,i+1,e,k,sum,ans);
        if(left != 0 || right != 0)
            temp = max(temp,max(left,right));
    }
    ans = max(ans,temp);
    return temp;
}
int longSubarrWthSumDivByK(int arr[], int n, int k){
    int sum = 0;
    for(int i =0;i<n;i++)
        sum += arr[i];
    int ans = 0;
    solve(arr,0,n-1,k,sum,ans);
    return ans;
}
vector<int> solve(vector<vector<int>> arr,int r,int c){
    int n = ceil(r/2.0);
    int fc,lc,fr,lr;
    vector<int> ans;
    fc=fr=0;
    lr = r-1;
    lc = c-1;
    int count = r*c;
    while(n--){
        for(int i =fc;i<=lc;i++) {
            if (count > 0)
                ans.push_back(arr[fr][i]);
            else
                break;
            count--;
        }
        fr++;
        for(int i = fr;i<=lr;i++){
            if (count > 0)
                ans.push_back(arr[i][lc]);
            else
                break;
            count--;
        }

        lc--;
        for(int i =lc;i>=fc;i--){
            if (count > 0)
                ans.push_back(arr[lr][i]);
            else
                break;
            count--;
        }

        lr--;
        for(int i =lr;i>=fr;i--){
            if (count > 0)
                ans.push_back(arr[i][fc]);
            else
                break;
            count--;
        }

        fc++;
    }
    return ans;
}
ll mx = 1e9+7;
ll countStrings(int n) {
    ll a,b;
    a=b=1;
    while(n--){
        a = (a+b)%mx;
        b = (a-b);
    }
    return a;
}
int CountWays(string str){
    if(str[0] == '0')
        return 0;
    vector<int> dp(str.size());

    dp[0] = 1;
    if(str[1] == '0'){
        if( str[0] == '1' || str[0] == '2')
            dp[1] = dp[0];
        else
            return 0;
    }
    else if(str[0] == '1' || (str[0] == '2' && str[1] >= '1' && str[1] <= '6'))
        dp[1] = 2;
    else
        dp[1] = 1;
    for(int i = 2;i<str.size();i++){
        if(str[i] == '0'){
            if( str[i-1] == '1' || str[i-1] == '2')
                dp[i] = dp[i-2];
            else
                return 0;
        }
        else if(str[i-1] == '1' || (str[i-1] == '2' && str[i] >= '1' && str[i] <= '6'))
            dp[i] = dp[i-1]+dp[i-2];
        else
            dp[i] = dp[i-1];
    }
    return dp[str.size()-1];
}
int maxSumIS(int arr[], int n)  {
    map<int,int> temp;
    int ans = 0;
    for(int i =0;i<n;i++){
        auto itr = temp.begin();
        int max = 0;
        while(itr != temp.end()){
            if(arr[itr->first] <= arr[i] && max < itr->second)
                max = itr->second;
            itr++;
        }
        max += arr[i];
        temp.insert({i,max});
        ans = ans<max?max:ans;
    }
    return ans;
}
int main() {
    vector<int> arr = {1, 101, 2, 3, 100};
    cout<<maxSumIS(arr.data(),arr.size());
    return 0;
}
