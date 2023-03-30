struct Item{
    int value;
    int weight;
};
bool comp(Item a,Item b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n){

    sort(arr,arr+n,comp);
    double ans = 0;
    for(int i =0;i<n && W > 0;i++){
        if(arr[i].weight <= W){
            ans += arr[i].value;
            W -=  arr[i].weight;
        }else {
            ans += ((arr[i].value/(double)arr[i].weight)*W);
            W = 0;
        }
    }
    return ans;
}