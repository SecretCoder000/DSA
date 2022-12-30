void solve1(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++)
            cout<<"*";
        cout<<endl;
    }
}


void solve2(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void solve3(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}

void solve4(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<i+1;
        }
        cout<<endl;
    }
}

void solve5(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void solve6(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}

void solve7(int n){
    int temp = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i-1;j++)
            cout<<" ";
        for(int j = 0;j<=temp;j++)
            cout<<"*";
        temp += 2;
        cout<<endl;
    }
}

void solve8(int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<i;j++)
            cout<<" ";
        for(int j =0;j<2*n-1-2*i;j++)
            cout<<"*";
        cout<<endl;
    }
}

int solve9(int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<n-i-1;j++)
            cout<<" ";
        for(int j =0;j<2*i+1;j++)
            cout<<"*";
        cout<<endl;
    }
    for(int i =1;i<n;i++){
        for(int j =0;j<i;j++)
            cout<<" ";
        for(int j = 0;j<2*n-1-2*i;j++)
            cout<<"*";
        cout<<endl;
    }
}

void solve10(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    for(int i =1;i<n;i++){
        for(int j =0;j<n-i;j++)
            cout<<"*";
        cout<<endl;
    }
}
void solve11(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<=i;j++){
            if(i%2 == 0){
                if(j%2 == 0)
                    cout<<1;
                else
                    cout<<0;
            }else {
                if(j%2 == 0)
                    cout<<0;
                else
                    cout<<1;
            }
        }
        cout<<endl;
    }

}