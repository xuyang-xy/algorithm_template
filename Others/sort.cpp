//O(n^2)
void BubbleSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

//O(n^2)
void SelectionSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        int index = i;
        for (int j = i + 1; j < len; j++)
            if (nums[j] < nums[index])
                index = j;
        swap(nums[i], nums[index]);
    }
}

//O(n^2)
void InsertionSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        int j = i;
        int temp = nums[i + 1];
        while (j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

void ShellSort(vector<int> &nums) {
    int len = nums.size();
    for (int step = len / 2; step > 0; step /= 2) {
        for (int i = 0; i < step; i++) {
            for (int j = i + step; j < len; j += step) {
                int temp = nums[j];
                int pre_index = j - step;
                while (pre_index >= 0 && nums[pre_index] > temp) {
                    nums[pre_index + step] = nums[pre_index];
                    pre_index -= step;
                }
                nums[pre_index + step] = temp;
            }
        }
    }
}