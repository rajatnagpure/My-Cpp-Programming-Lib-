// If the N = p1^k1 * p2^k2 * p3^k3 * .... * pn^kn
// phi(N) = p1^k1*(1-1/p1) * p2^k2*(1-1/p2) * ... * pn^kn(1-1/pn) = N * (1-1/p1)*(1-1/p2)*(1-1/p3)* ... * (1-1/pn)

// **** SUM OF TOTIENT OF DIVSOR OF ANY INTEGER N IS N

int phi(int n){
    int res = n;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            res /= i;
            res *= (i-1);

            while(n%i == 0) n /= i;
        }
    }

    if(n > 1){
        res /= n;
        res *= (n-1);
    }
    return res;
}




// #####################################################

int phi[N];

void init(int n){
    for(int i=0;i<n;i++) phi[i] = i;
    for(int i=2;i<n;i++){
        if(phi[i] == i){
            for(int j = i;j<n; j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}
