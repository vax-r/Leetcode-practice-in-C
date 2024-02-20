int missingNumber(int* nums, int numsSize) {
    const int n = numsSize;
    char miss[n + 2];
    memset(miss, '0', (n+2) * sizeof(char));

    for (int i=0; i<numsSize; i++)
        miss[nums[i]] = '1';
    
    int missing;
    for (int i=0; i < n+1; i++) {
        if (miss[i] == '0') {
            missing = i;
            break;
        }
    }
    return missing;
}