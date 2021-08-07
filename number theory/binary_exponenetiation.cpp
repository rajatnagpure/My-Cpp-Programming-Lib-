int bin_exp(int a,int n){
    int res=1;
    while(n){
        if(n%2)
            res *= a,n--;
        a *= a, n/= 2;
    }
    return res;
}

int bin_exp_mod(int a,int n){
    int res=1;
    while(n){
        if(n%2)
            res = (res*a)%MOD,n--;
        a = (a*a)%MOD, n/= 2;
    }
    return res;
}



/////////////////// for 1<=n<=2^(64-1) ///////////////

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

