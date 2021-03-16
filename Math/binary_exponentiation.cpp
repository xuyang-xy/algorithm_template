double PowerPow(double a, long long b) {
    double res = 1.0;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int PowerPow(long long a, long long b, long long m) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

/*
[F[n] F[n - 1]        [1 1 ^ (n - 1)
 F[n - 1] F[n - 2]] =  1 0]
*/
struct Matrix {
    long long a[Max_rank][Max_rank];
    Matrix() {
        memset(a, 0, sizeof(a));
    }
    void init(){
        a[1][1] = a[1][2] = a[2][1] = 1;
        a[2][2] = 0;
    }
    Matrix operator*(const Matrix b) {
        Matrix res;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++)
                for (int u = 1; u <= 2; u++)
                    res.a[i][j] = (res.a[i][j] + a[i][u] * b.a[u][j]) % mod;
        return res;
    }
};
long long PowerPow(long long n){
    Matrix ans, base;
    ans.init();
    base.init();
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans.a[1][1];
}