
bool isTimeEnough( vector<int> & ranks,int total_cars,ll givenTime){
    ll cars = 0;
    for(auto it : ranks){
        ll count = givenTime/it;
        ll temp = sqrt(count);
        cars += temp;
    }
    return cars >= total_cars;
}
ll repairCars(vector<int>& ranks, int cars) {
    ll l,r;
    l = 1,r = 1e14;
    while (l < r ){
        ll mid = (l+r)/2;
        if(isTimeEnough(ranks,cars,mid))
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

