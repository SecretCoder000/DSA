bool isAnagram(string a, string b){
    if(a.size() != b.size())
        return false;
    vector<int> arr(26,0);
    for(int i =0;i<a.size();i++)
        arr[a[i]-97]++;
    for(int i =0;i<b.size();i++)
        arr[b[i]-97]--;
    for(int i =0;i<26;i++)
        if(arr[i] != 0 )
            return false;
    return true;
}