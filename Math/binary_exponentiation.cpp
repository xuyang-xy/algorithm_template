double PowerPow(double a, long long b) {
    double res = 1.0;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}