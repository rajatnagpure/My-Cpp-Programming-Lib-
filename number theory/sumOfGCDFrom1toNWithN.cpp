
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

void sumOfGCDFrom1toNWithN(){
    int n;
    cin>>n;
    int res = 0;
    for(int i=0;i*i<=n;i++)
    if(n % i == 0){
        int d1 = i;
        int d2 = N/i;

        res += d1 * phi[n/d1];

        if(d2!=d1)
        res += d2 * phi[n/d2];
    }
    cout<<res<<endl;
}
