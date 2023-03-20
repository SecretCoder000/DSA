#include<bits/stdc++.h>
using namespace std;
int countIsland(vector<vector<int>> arr){
	int max = INT_MIN;
	for(int i =0;i<arr.size();i++){
		for(int j =0;j<arr[i].size();j++){
			if(arr[i][j] == 1){
				queue<pair<int,int>> st;
				st.push({i,j});
				while(!st.empty()){
					max = max<st.size()?st.size():max;
					int l = st.front().first;
					int r = st.front().second;
					if(arr[l][r] == 2){
					    st.pop();
					    continue;
					}
					arr[l][r] = 2;
					if(l != 0 && arr[l-1][r] == 1)
						st.push({l-1,r});
					if(l != arr.size()-1 && arr[l+1][r] == 1)
						st.push({l+1,r});
					if(r != 0 && arr[l][r-1] == 1)
						st.push({l,r-1});
					if(r != arr[l].size()-1 && arr[l][r+1] == 1)
						st.push({l,r+1});
					if(l != 0 && r != 0 && arr[l-1][r-1] == 1)
					    st.push({l-1,r-1});
					if(l != arr.size()-1 && r != arr[l].size()-1 && arr[l+1][r+1] == 1)
					    st.push({l+1,r+1});
					if(l != arr.size()-1 && r != 0 && arr[l+1][r-1] == 1)
					    st.push({l+1,r-1});
					if(l != 0 && r != arr[l].size()-1 && arr[l-1][r+1] == 1)
					    st.push({l-1,r+1}); 
					st.pop();
				}
			}
		}
	}	
	return max;
}
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        vector<vector<int>> arr(n,vector<int> (m,0));
        vector<int> ans;
        for(int i =0;i<op.size();i++){
            arr[op[i][0]][op[i][1]] = 1;
            ans.push_back(countIsland(arr));
        }
        return ans;
    }