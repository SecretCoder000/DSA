vector<int> candyStore(int candies[], int n, int k){
    int min,max;
    max=min=0;

    sort(candies,candies+n);
    k++;
    int minIteration = n/k;
    if(n%k!=0)
        minIteration++;
    for(int i =0;i<minIteration;i++){
        min += candies[i];
        max += candies[n-1-i];
    }
    return {min,max};
}