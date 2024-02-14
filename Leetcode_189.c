void rotate(int* nums, int numsSize, int k) {
    if (k >= numsSize)
        k = k % numsSize;
    if (!k)
        return;
    int *tmp = calloc(k, sizeof(int));
    memmove(tmp, nums + (numsSize - k), k * sizeof(int));
    memmove(nums + k, nums, (numsSize - k) * sizeof(int));
    memmove(nums, tmp, k * sizeof(int));
}