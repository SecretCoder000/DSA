int search(string pat, string txt) {
    vector<int> temp1(26,0);
    vector<int> temp2(26,0);
    int k = pat.size();
    int n = txt.size();
    for(int i =0;i<k;i++){
        temp1[pat[i]-97]++;
        temp2[txt[i]-97]++;
    }
    int count = 0;
    if(temp1 == temp2)
        count++;
    for(int i = k;i<n;i++){
        temp2[txt[i-k]-97]--;
        temp2[txt[i]-97]++;
        if(temp1 == temp2)
            count++;
    }
    return count;
}