int findMatching(string text, string pat) {
    int n = text.size();
    int m = pat.size();
    for(int i =0;i<=n-m;i++){
        if(text[i] == pat[0]){
            bool flag = false;
            for(int k = 0;k<m;k++){
                if(pat[k] != text[i+k]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                return i;
            }
        }
    }
    return -1;
}