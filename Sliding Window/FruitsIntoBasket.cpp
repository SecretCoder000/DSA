int totalFruits(int n, vector<int> &arr) {
    map<int,int> temp;
    int i,j;
    i=j=0;
    int ans = 0;
    while(j < n){
        if(temp.size() < 2 || (temp.size() == 2 && temp.find(arr[j]) != temp.end())){
            temp[arr[j]]++;
            ans = max(ans,j-i+1);
            j++;
        }else {
            temp[arr[i]]--;
            if(temp[arr[i]] == 0)
                temp.erase(temp.find(arr[i]));
            i++;
        }
    }
    return ans;
}