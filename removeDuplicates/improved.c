int removeDuplicates(int* nums, int numsSize) {
    // [1,1,1,2,2,3]
    int i = 0;
    int16_t j = 0;
    int16_t latest = -10001;
    int16_t count = 1;

    while (j < numsSize) {
        if (latest == nums[j]) {
            count++;
        } else {
            count = 1;
        }
        if (count <= 2) {
            nums[i] = nums[j];
            i++;
        }
        latest = nums[j];
        j++;
    }

    return i;
}