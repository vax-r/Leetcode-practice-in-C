int firstBadVersion(int n) {
    int left = 0, right = n;
    int mid;
    while (right > left) {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}