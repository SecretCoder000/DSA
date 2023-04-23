int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
    int i,j,k;
    i=j=k=0;

    for(int i = n1-2;i>-1;i--)
        s1[i] += s1[i+1];
    for(int i = n2-2;i>-1;i--)
        s2[i] += s2[i+1];
    for(int i = n3-2;i>-1;i--)
        s3[i] += s3[i+1];
    while (i <n1 && j < n2 && k < n3){
        if(s1[i] == s2[j] && s2[j] == s3[k])
            return s1[i];
        else if(s1[i] > s2[j] || s1[i] > s3[k])
            i++;
        else if(s2[j] > s1[i] || s2[j] > s3[k])
            j++;
        else
            k++;
    }
    return 0;
}