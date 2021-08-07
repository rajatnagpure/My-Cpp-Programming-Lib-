
// CAATALAN NUMBER
// C0 = C1 = 1
// C2 = C0*C1 + C1*C0 = 2
// C3 = C2*C0 + C1*C1 + C0*C2 = 5
// C4 = C3*C0 + .... = 14
// Cn = C0*C(n-1) + C1*C(n-2) + ... + Ci*C(n-i-1) + ....... +C(n-1)*C0

// solution 1

int Catalan(int n){
    if(n == 1 || n == 0 ) return 1;
    int res = 0;
    for(int i=0;i<n;i++){
        res += Catalan(i)*Catalan(n-i-1);
    }
    return res;
}

// solution 2

#define N 100

int cat[N];

void Catalan(){
    cat[0] = cat[1] = 1;
    for(int n=2;n<N;n++){
        cat[n] = 0;
        for(int i=0;i<n;i++){
            cat[n] += cat[i]*cat[n-i-1];
            cat[n] %= MOD;
        }
    }
}

// Nth catalan number
// Cat[N] = (2*n)! / (n+1)! or  = (1/(n+1))*((2*n)! / n!)

int binomialCoeff(int n, int k){
    int res = 1;
    if (k > n - k)
        k = n - k; 
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int catalan(unsigned int n){
    int c = binomialCoeff(2 * n, n);
    return c / (n + 1);
}


// Nth Catalan Number in modular field

int binomialCoeff(int n, int r, int& div){
    if (r > n)
        return 0;
    int inv[r + 2] = { 0 };
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;

    for (int i = 2; i <= r+1; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
    div = inv[r+1];
    int ans = 1;
 
    for (int i = 2; i <= r; i++) {
        ans = ((ans % MOD) * (inv[i] % MOD)) % MOD;
    }
 
    for (int i = n; i >= (n - r + 1); i--) {
        ans = ((ans % MOD) * (i % MOD)) % MOD;
    }
    return ans;
}

int Catalan(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int div = 0;
    int res = binomialCoeff(2*n,n,div);
    return (res * div)%MOD;
}


