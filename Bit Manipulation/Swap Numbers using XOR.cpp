
vector<int> swap(int a,int b){
    int c = a^b;
    a = c^a;
    b = c^b;
    return {a,b};
}