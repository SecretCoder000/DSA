#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    ans.push_back(arr[0]);
    int j = 0;
    for(int i =1;i<arr.size();i++){
        if(arr[i][0]>=ans[j][0] && arr[i][1]<=ans[j][1])
            continue;
        else if(arr[i][0]>=ans[j][0] && arr[i][1]>ans[j][1])
            ans[j][1] = arr[i][1];
        else if(arr[i][0] > ans[j][1]){
            ans.push_back(arr[i]);
            j++;
        }
    }
    return ans;
    }
int main() {
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(arr);
    
    return 0;
}