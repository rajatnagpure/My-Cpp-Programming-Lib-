// Time complexity - O(n)
long long nCr(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


// Time Complexity - O(n^2) Space Complexity - O(n^2)
# define MAX 100 // assuming we need first 100 rows
long long triangle[MAX + 1][MAX + 1];

void makeTriangle() {
    int i, j;

    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < MAX; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

long long nCr(int n, int r) {
    return triangle[n][r];
}

// Time Complexity - O(n^2) Space Complexity - O(n)
# define MAX 100
long long row[MAX + 1];

int nCr(int n, int r) {
    int i, j;

    // initialize by the first row
    row[0] = 1; // this is the value of C(0, 0)

    for(i = 1; i <= n; i++) {
        for(j = i; j > 0; j--) {
             // from the recurrence C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
             row[j] += row[j - 1];
        }
    }

    return row[r];
}


// Reference - https://stackoverflow.com/questions/11809502/which-is-better-way-to-calculate-ncr



// GCD Technique
// Time - O(n* log(n)) Space - O(n)
// By diving divifing the numerator and denominator with gcd of the i and n-r+i+1
// and then multipying the the reduced numnerator by modular rule

int nCr(int n,int r){
    if(r>n) return 0;
    if(r>n-r) r = n-r;
    int arr[r];
    for(int i=n-r+1; i<=n ;i++){
        arr[i+r-n-1] = i;
    }
    int ans = 1;
    for(int k = 1;k<r+1; k++){
        int j = 0, i=k;
        while(j<r){
            int x = __gcd(i,arr[j]);
            if(x>1){
                arr[j] /= x;
                i /= x;
            }
            if(i == 1) break;
            j += 1;
        }
    }
    for(int i: arr)
        ans = (ans*i)%MOD;
    return ans;
}


// Modular Inversion technique
// Time - O(n+k) and space - O(n)

int nCr(int n, int r){
    if (r > n)
        return 0;
    int m = 1000000007;
    int inv[r + 1] = { 0 };
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;

    for (int i = 2; i <= r; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % m;
    }
 
    int ans = 1;
 
    for (int i = 2; i <= r; i++) {
        ans = ((ans % MOD) * (inv[i] % MOD)) % MOD;
    }
 
    for (int i = n; i >= (n - r + 1); i--) {
        ans = ((ans % MOD) * (i % MOD)) % MOD;
    }
    return ans;
}


