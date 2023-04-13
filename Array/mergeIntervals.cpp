#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    ans.push_back(arr[0]);
    for(int i =1;i<n;i++){
        int ind = ans.size()-1;
        int end = ans[ind][1];
        if(arr[i][0] <= end ){
            if(arr[i][1] > end)
                ans[ind][1] = arr[i][1];
        }
        else
            ans.push_back(arr[i]);
    }
    return ans;
}
int main() {
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = overlappedInterval(arr);
    return 0;
}