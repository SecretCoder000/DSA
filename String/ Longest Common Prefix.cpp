string longestCommonPrefix(vector<string>& arr) {
    string word;
    int m = INT_MAX;
    int n = arr.size();
    for(int i =0;i<n;i++)
        m = min(m,(int)arr[i].size());
    for(int i =0;i<m;i++){
        char ch = arr[0][i];
        for(int j =0;j<n;j++){
            if(arr[j][i] != ch){
                ch = '0';
                break;
            }
        }
        if(ch != '0')
            word.push_back(ch);
        else
            break;
    }
    return word;
}