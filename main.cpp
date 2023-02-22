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
void stockBuySell(int arr[], int n) {
    vector<vector<int>> ans;
    int buy,sell,flag;
    buy=sell=flag = 0;
    for(int i =1;i<n;i++){
        if(arr[i]>= arr[i-1] && arr[i] != arr[buy]){
            sell++;
            flag = 1;
        }else if(buy == sell)
            buy=sell=i;
        else {
            ans.push_back({buy,sell});
            buy=sell=i;
        }
    }
    if(flag == 1 && buy != n-1 && sell == n-1)
        ans.push_back({buy,sell});
    for(int i =0;i<ans.size();i++)
        cout<<"("<<ans[i][0]<<","<<ans[i][1]<<")"<<" ";
}
int minSubArrayLen(vector<int>& nums,int target) {
    int ans = nums.size()+1;
    int i =0;
    int j =0;
    int sum = 0;
    while(j<nums.size()){
        if(sum<target){
            sum += nums[j];
            j++;
        }
        if(sum>=target) {
            ans = min(ans,j-i);
            sum -= nums[i];
            i++;
        }
    }
    while(sum>=target){
        ans = min(ans,j-i);
        sum -= nums[i];
        i++;
    }
    return (ans==nums.size()+1)?0:ans;
}
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k == 0)
        return 0;
    int ans = 0;
    int sum = 1;
    int i =0;
    int j =0;
    while(j<nums.size() && i <= j){
        if(sum*nums[j]<k){
            sum *= nums[j];
            j++;
            ans += (j-i);
        }else {
            sum /= nums[i];
            if(sum == 0)
                sum = 1;
            i++;
        }
        if(i>j)
            j=i;
    }
    return ans;
}
string minWindow(string s, string t) {
    map<char,int> mp;
    for(int i =0;i<t.size();i++)
        mp[t[i]]++;
    int i,j;
    i=j=0;
    int count = mp.size();

    string str= "";
    string ans = "";
    while(j<s.size()){
        if(count > 0){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            j++;
        }else {
            if(ans.empty())
                ans = s.substr(i,j-i);
            else
                ans = ans.size()>(j-i)?s.substr(i,j-i):ans;
            if(mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    count++;
            }
            i++;
        }
    }
    while(count == 0 && i < s.size()){
        if(ans.empty())
            ans = s.substr(i,j-i);
        else
            ans = ans.size()>(j-i)?s.substr(i,j-i):ans;
        if(mp.find(s[i]) != mp.end()) {
            mp[s[i]]++;
            if (mp[s[i]] > 0)
                count++;
        }
        i++;
    }
    return ans;
}
int longestSubstring(string s, int k) {
    if(s.size()<k)
        return 0;
    map<char,int> temp;
    for(int i =0;i<s.size();i++)
        temp[s[i]]++;
    int ans = 0;
    for(int i =0;i<s.size();i++){
        if(temp[s[i]] < k){
            ans = max(longestSubstring(s.substr(0,i),k), longestSubstring(s.substr(i+1),k));
            break;
        }
        ans++;
    }
    return ans;
}

int longestPalindrome(string x) {
    int n = x.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    for(int i =1;i<n;i++){
        if(x[i] == x[i-1]){
            dp[i-1][i] = 1;
        }
        else
            dp[i-1][i] = 0;
    }
    int ans = 0;
    for(int j =2;j<n;j++){
        for(int i = 0;i<(n-j);i++){
            int k = i+j;
            if(x[i] == x[k] && dp[i+1][k-1] == 1){
                dp[i][k] = 1;
                ans++;
            }else
                dp[i][k] =0;
        }
    }
    return ans;
}
int solve(vector<int> arr,int n,int k,vector<vector<int>> & dp) {
    if(dp[n][k] == -1){
        if(arr[n-1]<=k)
            dp[n][k] = solve(arr,n-1,k/arr[n-1],dp)+solve(arr,n-1,k,dp)+1;
        else
            dp[n][k] = solve(arr,n-1,k,dp);
    }
    return dp[n][k];
}
int activitySelection(vector<int> start, vector<int> end, int n){
       vector<pair<int,int>> arr;
       for(int i =0;i<n;i++)
           arr.push_back({end[i],start[i]});
       sort(arr.begin(),arr.end());
       int count = 0;
       int i ,j;
       i=0;
       j=1;
       while(j<n){
            if(arr[i].first < arr[j].first && arr[i].first != arr[j].second){
                count++;
                i = j;
                j++;
            }
            else
                j++;
            if(j == n)
                count++;
       }
       return count;
    }
bool solve1(vector<vector<int>> & grid ,int i,int j){
    if(i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size())
        return false;
    if(grid[i][j] == 0)
        return false;
    if(grid[i][j] == 2 )
        return true;
    grid[i][j] = 0;
    return solve1(grid,i-1,j) || solve1(grid,i+1,j) || solve1(grid,i,j+1) || solve1(grid,i,j-1);

}
bool is_Possible(vector<vector<int>>& grid) {
    pair<int,int> start = {-1,-1};
    for(int i =0;i<grid.size();i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                start = {i, j};
                break;
            }
        }
        if(start.first != -1)
            break;
    }

    return solve1(grid,start.first,start.second);
}
void solve(vector<int> & arr,int x){
    int carry = 0;
    for(int i =arr.size()-1;i>=0;i--){
        int temp = arr[i]*x+carry;
        arr[i] = temp%10;
        carry = temp /10;
    }
    while(carry>0){
        int r = carry%10;
        carry/=10;
        arr.insert(arr.begin(),r);
    }
}
vector<int> factorial(int n){
    vector<int> arr = {1};
    for(int i =2;i<=n;i++)
        solve(arr,i);
    return arr;
}
int findNext (int N) {
    vector<int> temp ;
    while(N>0){
        int r = N%10;
        if(!temp.empty() && r < temp[0]){
            break;
        }
        N /=10;
        temp.insert(temp.begin(),r);
    }
    if(N > 0)
        for(int i = temp.size()-1;i>=0;i--){
            if(temp[i] > N%10){
                int r = N%10;
                N = N/10;
                N = N*10+temp[i];
                temp[i] = r;
                break;
            }
        }
    sort(temp.begin(),temp.end());
    for(int i =0;i<temp.size();i++)
        N = N*10 + temp[i];
    return N;
}
struct Node {
    int val;
    Node* left;
    Node * right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    cout << node->val << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}
bool isBST(Node * root,Node * &prev){
    if(root == NULL)
        return true;
    else {
        if(!isBST(root->left,prev))
            return false;
        if(prev && prev->val >= root->val)
            return false;
        prev = root;
        return isBST(root->right,prev);
    }
}
Node * solve(int arr[],int i,int j){
    if(i > j)
        return NULL;
    Node * root = new Node(arr[i]);
    if(i == j)
        return root;
    int ind = -1;
    for(int k =i+1;k<=j;k++){
        if(arr[k] < arr[i]){
            ind = k;
        }else
            break;

    }
    if(ind == -1){
        root->left = NULL;
        root->right = solve(arr,i+1,j);
    }
    else {
        root->left = solve(arr,i+1,ind);
        root->right = solve(arr,ind+1,j);
    }
    return root;
}
int longestOnes(int n, vector<int>& nums, int k) {
    int count = 0;
    int ans = INT_MIN;
    int i,j;
    i=j=0;
    while(j<nums.size()){
        if(count<k){
            if(nums[j] == 0)
                count++;
            ans = max(ans,j-i+1);
            j++;
        }else if(count == k && nums[j] == 1){
            ans = max(ans,j-i+1);
            j++;
        }else {
            if(nums[i] == 0)
                count--;
            i++;
        }
    }
    return ans;
}
int characterReplacement(string s, int k) {
    int i,j;
    i=j=0;
    pair<char,int> max={s[0],0};
    map<char,int> temp;
    int ans = 0;
    while(j < s.size()){
        if(j-i-max.second < k || ((j-i-max.second) == k && s[j] == max.first)){
            temp[s[j]]++;
            for(int m = 0;m<temp.size();m++)
                if(temp[s[j]] > max.second)
                    max = {s[j],temp[s[j]]};
            ans = ans<(j-i+1)?(j-i+1):ans;
            j++;
        }else {
            if(s[i] == max.first)
                max.second--;
            temp[s[i]]--;
            if(temp[s[i]] == 0)
                temp.erase(temp.find(s[i]));
            i++;
        }
    }
    return ans;
}
int subarrayCount(vector<int> &arr, int n, int k) {
    int i,j;
    map<int,int> temp;
    i=j=0;
    int sum = 0;
    while(j<n){
        if(temp.size() <= k){
            temp[arr[j]]++;
            if(temp.size()>k)
                continue;
            if(temp.size() == k)
                sum++;
            j++;
        }
        else {
            while(temp.size()>k){
                temp[arr[i]]--;
                if(temp[arr[i]] == 0)
                    temp.erase(temp.find(arr[i]));
                i++;
            }
            if(temp.size() == k)
                sum++;
        }
    }
    return sum;
}
int numberOfSubarrays(vector<int>& arr, int n, int target){
    map<int,int> temp;
    int j,sum;
    j=sum=0;
    int ans =0;
    while(j<n){
        sum += arr[j];
        if(sum == target)
            ans++;
        if(temp.find(sum-target) != temp.end())
            ans += temp[sum-target];
        if(temp.find(sum) != temp.end())
            temp[sum]++;
        else
            temp.insert({sum,1});
        j++;
    }
    return ans;
}
int countSubarray(int n, vector<int>& arr, int target) {
    for(int i =0;i<n;i++) {
        if(arr[i]%2==0)
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    map<int,int> temp;
    int j,sum;
    j=sum=0;
    int ans =0;
    while(j<n){
        sum += arr[j];
        if(sum == target)
            ans++;
        if(temp.find(sum-target) != temp.end())
            ans += temp[sum-target];
        if(temp.find(sum) != temp.end())
            temp[sum]++;
        else
            temp.insert({sum,1});
        j++;
    }
    return ans;
}


int main() {
    vector<vector<int>> adj = {{2,1,0},{1,1,0},{0,1,1}};
    return 0;
}
