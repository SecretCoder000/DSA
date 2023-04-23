int sum(int n){
    return (n*(n+1))>>1;
}
int sumOfMultiples(int n) {
    int divisibleBy3 = n/3;
    int divisibleBy5 = n/5;
    int divisibleBy7 = n/7;
    int divisibleBy15 = n/15;
    int divisibleBy21 = n/21;
    int divisibleBy35 = n/35;
    int divisibleBy357 = n/(35*3);
    return 3*(sum(divisibleBy3))+5*(sum(divisibleBy5))+7*(sum(divisibleBy7))-15*((sum(divisibleBy15)))-21*((sum(divisibleBy21)))
           -35*((sum(divisibleBy35)))+35*3*((sum(divisibleBy357)));
}