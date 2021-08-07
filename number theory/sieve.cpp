#define N 100005

bool prime[N];

void sieve(){
    for(int i=2;i*i<N;i++){
        if(!prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j] = true;
            }
        }
    }
}
