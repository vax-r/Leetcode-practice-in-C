int rob(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    
    int t1, t2;
    int gain[numsSize];
    gain[0] = nums[0];
    gain[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i=2; i<numsSize - 1; i++) {
        gain[i] = (nums[i] + gain[i-2]) > (gain[i-1]) ? (nums[i] + gain[i-2]) : (gain[i-1]);
    }
    t1 = gain[numsSize - 2];

    gain[1] = nums[1];
    gain[2] = nums[1] > nums[2] ? nums[1] : nums[2];
    for (int i=3; i<numsSize; i++) {
        gain[i] = (nums[i] + gain[i-2]) > (gain[i-1]) ? (nums[i] + gain[i-2]) : (gain[i-1]);
    }
    t2 = gain[numsSize - 1];
    return t1 > t2 ? t1 : t2;
}