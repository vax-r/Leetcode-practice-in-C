int countPrimes(int n) {
    int *prime = calloc(n, sizeof(int));
    for (int i=2; i<n; i++)
        prime[i] = 1;
    
    int ans = 0;
    for (int i=2; i<n; i++) {
        if (prime[i]) {
            for (int j = i << 1; j < n; j += i)
                prime[j] = 0;
            ans += 1;
        }
    }
    free(prime);
    return ans;
}