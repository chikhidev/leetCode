int removeDuplicates(int* nums, int numsSize) {
    // [1,1,1,2,2,3]
    int i = 0;
    int j = 0;
    int* latest = NULL;
    int count = 1;

    while (j < numsSize) {
        if (latest && *latest == nums[j]) {
            count++;
        } else {
            count = 1;
        }
        if (count <= 2) {
            nums[i] = nums[j];
            i++;
        }
        latest = &nums[j];
        j++;
    }

    return i;
}