int rob(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    
    int gain[numsSize];
    gain[0] = nums[0];
    gain[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i=2; i<numsSize; i++) {
        gain[i] = (nums[i] + gain[i-2]) > (gain[i-1]) ? (nums[i] + gain[i-2]) : (gain[i-1]);
    }
    return gain[numsSize - 1];
}