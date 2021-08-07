#define N 100005

bool prime[N];

void sieve(){
	prime[0] = prime[1] = true;
    for(int i=2;i*i<N;i++){
        if(!prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j] = true;
            }
        }
    }
}
