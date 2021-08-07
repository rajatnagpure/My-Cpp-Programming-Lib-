vector<int> prime;

void sieve(){
    bool ar[N];
    for(int i=0;i<N;i++) ar[i] = false;

    for(int i=2;i*i<N;i++){
        if(!ar[i]){
            for(int j=i*i;j<N;j+=i){
                ar[j] = true;
            }
        }
    }
    for(int i=2;i<N;i++)
    if(!ar[i]) prime.EB(i);
}

void segmentedSieve(int L,int R){
    if(L==1) L++;
    int mN = R-L+1;
    bool ar[mN] = {false};
    for(int p:prime)
    if(p*p<=R){
        int i = (L/p)*p;
        if(i<L) i+=p;
        for(;i<=R;i+=p){
            if(i!=p)
                ar[i-L] = true;
        }
    }

    for(int i=0;i<mN;i++){
        if(!ar[i]) 
            cout<<L+i<<endl;
    }
}
