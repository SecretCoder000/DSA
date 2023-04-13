int buyMaximumProducts(int n, int k, int price[]){
    set<pair<int,int>> temp;
    for(int i =0;i<n;i++)
        temp.insert({price[i],i+1});
    int stocks = 0;
    for(auto itr : temp){
        int minStock = min(itr.second, k/price[itr.second-1]);
        stocks += minStock;
        k -= (minStock*itr.first);
    }
    return stocks;
}