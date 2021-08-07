// when m is prime number

int mod_mul_inv(int a,int m){
    int res = 1,n = m-2;
    while(n){
        if(n%2) res = ((res%m)*(a%m)) %m,n--;
        a = ((a%m)*(a%m))%m,n/=2;
    }
    return res;
}


// when a and m are co prime but m is not prime

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
