int maxRotateFunction(int* nums, int numsSize) {
    int tmp = 0, sum = 0, max;
    for (int i=0; i<numsSize; i++) {
        tmp += (nums[i] * i);
        sum += nums[i];
    }
    max = tmp;

    for (int i=1; i<numsSize; i++) {
        tmp = tmp + sum - (numsSize * nums[numsSize - i]);
        max = max > tmp ? max : tmp;
    }
    return max;
}