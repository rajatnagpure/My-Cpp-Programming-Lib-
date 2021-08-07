// if 18 = 3^2 * 2^1 then tot_div = (pow1+1)*(pow2+1)*....
// eg 1,2,3,6,9,18 = 6 and (2+1)*(1+1) = 6

int tot_div(int a){
	int res = 1,t = 0;
	while(a%2 == 0){
		t++;
		a /= 2;
	}
	res *= (t+1);
	int x = sqrt(a);
	for(int i=3;i <= x;i+=2){
		t = 0;
		while(a%i == 0) {
			t++;
			a /= i;
		}
		res *= (t+1);
	}
	if(a>2) res *= 2;
	return res;
}
