double myPow(double x, int n) {
    if (n == 0)
        return 1;
    double half = myPow(x, n/2);
    if (n % 2 == 0)
        return half * half;
    return n > 0 ? half * half * x : half * half / x;
}