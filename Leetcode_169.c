int majorityElement(int* nums, int numsSize) {
    int element = nums[0], count = 1;
    for (int i=1; i<numsSize; i++) {
        if (nums[i] == element)
            count += 1;
        else
            count -= 1;
        
        if (!count) {
            element = nums[i];
            count = 1;
        }
    }
    return element;
}