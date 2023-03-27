int strstr(string s, string x)
{
    int l1=s.size();
    int l2=x.size();
    int c=0;
    int j =0;
    for(int i=0;i<l1;i++){
        if(s[i] == x[j]){
            c++;
            j++;
        }else {
            c = 0;
            i = i-j;
            j = 0;
        }
        if(c == l2)
            return i-c+1;
    }
    return -1;
}