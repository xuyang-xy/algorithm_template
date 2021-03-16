double sqrt(double x) {
    double l = sgn(x - 1.0) > 0 ? 0.0 : x;
    double r = sgn(x - 1.0) > 0 ? x : 0.0;
    while (sgn(r - l)) {
        double mid = l + (r - l) / 2.0;
        double temp = mid * mid;
        if (sgn(temp - xs) > 0) r = mid;
        else l = mid;
    }
    return l;
}