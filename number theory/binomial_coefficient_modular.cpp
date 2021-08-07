int mod_mul_inv(int a,int m){
    int res = 1,n = m-2;
    while(n){
        if(n%2) res = ((res%m)*(a%m)) %m,n--;
        a = ((a%m)*(a%m))%m,n/=2;
    }
    return res;
}

int C(int n,int k){
    if(n<k) return 0;
    int F[1000+1];
    F[0]=F[1] =1;
    for(int i=2;i<=1000;i++) F[i] = (F[i-1]*i)%MOD;
    int res = F[n];
    res = (res*mod_mul_inv(F[k],MOD))%MOD;
    res = (res*mod_mul_inv(F[n-k],MOD))%MOD;
    return res;
}
