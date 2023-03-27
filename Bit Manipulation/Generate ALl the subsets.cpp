bool checkBitSet(int n ,int i) {
    return n&(1<<i);
}
vector<vector<int>> generateAllTheSubset(vector<int> arr){
    int n = arr.size();
    int r = 1<<n;
    vector<vector<int>> ans;
    for(int i =0;i<r;i++){
        vector<int> subset;
        for(int j = 0;j<n;j++){
            if(checkBitSet(i,j))
                subset.push_back(arr[j]);
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    vector<vector<int>> ans = generateAllTheSubset({1,2,3});
    for(int i =0;i<ans.size();i++){
        for(auto it : ans[i])
            cout<<it<<"\t";
        cout<<endl;
    }
    return 0;
}