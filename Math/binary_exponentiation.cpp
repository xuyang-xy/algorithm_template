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