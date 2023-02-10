bool detectCapitalUse(string word) {
    int count = 0;
    for(int i =0;i<word.size();i++)
        if(word[i] >= 65 && word[i] <= 90)
            count++;
    return (count == 1 && word[0] >= 65 && word[0] <= 90) || count == word.size() || count == 0;
}