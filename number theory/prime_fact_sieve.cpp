#define N 1000001
int a[N];

void sieve(int n){
    memset(a,-1,N* sizeof(int));
    for(int i=2;i<=n;i++){
        if(a[i]==-1){
            a[i] = i;
            for(int j=i*i;j<n;j+=i)
                a[j]=i;
        }
    }
}

void prime_fact_sieve(int n){
    while(n!=1){
        cout<<a[n]<<" ";
        n = n/a[n];
    }
}
