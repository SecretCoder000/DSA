int minimumDays(int s, int n, int m){
    if(n < m)
        return -1;
    int daysCanBuy = s-s/7;
    int totalFoodReq = s*m;
    int daysReqToBuyFood = totalFoodReq/n+(totalFoodReq%n==0?0:1);
    if(daysReqToBuyFood > daysCanBuy)
        return -1;
    else
        return daysReqToBuyFood;
}