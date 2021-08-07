int mulmod(int a, int b,int c){
    int x = 0,y=a%c;
    while(b > 0){
    if(b%2 == 1){
        x = (x+y)%c;
    }
    y = (y*2LL)%c;
    b /= 2;
    }
    return x%c;
}

int bin_exp_mod(int a,int n,int mod){
    int res=1;
    while(n){
        if(n%2)
            res = mulmod(res,a,mod),n--;
        a = mulmod(a,a,mod), n/= 2;
    }
    return res;
}

bool fermatsPrimalityTest(int n,int iter = 5){
    if(n<4) return (n==2 || n==3);
    for(int i=0;i<=iter;i++){
        int a = 2+rand()%(n-3);
        if(bin_exp_mod(a,n-1,n) != 1) return false;
    }
    return true;
}

