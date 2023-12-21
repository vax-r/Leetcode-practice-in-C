int divide(int dividend, int divisor) {
    int sign = (dividend >= 0 ^ divisor >= 0) ? -1 : 1;
    long long quotient = 0;
    long long dividendL = dividend;
    long long divisorL = divisor;

    dividendL = dividendL > 0 ? dividendL : -dividendL;
    divisorL = divisorL > 0 ? divisorL : -divisorL;

    for (int i=32; i>=0; i--) {
        if ((dividendL >> i) >= divisorL) {
            dividendL -= (divisorL << i);
            quotient += (1LL << i);
        }
    }
    if (sign > 0 && quotient > INT_MAX)
        return INT_MAX;
    return sign > 0 ? (int) quotient : (int) -quotient;
}