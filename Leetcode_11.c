int maxArea(int* height, int heightSize) {
    int n = heightSize;
    int maxA = height[0] < height[n - 1] ? height[0] * (n - 1) : height[n - 1] * (n - 1);

    // init value of i, j
    int i = 0, j = n-1;
    while (j > i) {
        int tmpA = height[i] < height[j] ? height[i] * (j - i) : height[j] * (j - i);
        maxA = maxA > tmpA ? maxA : tmpA;
        height[i] < height[j] ? i++ : j--;
    }

    return maxA;
}
