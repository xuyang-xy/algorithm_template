//O(n^2) stable
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

//O(n^2) stable
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

//O(nlogn)
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

//O(nlogn)
int partition(vector<int> &n, int l, int r) {
    int pivot = n[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (n[j] <= pivot) {
            i++;
            swap(n[i], n[j]);
        }
    }
    swap(n[i + 1], n[r]);
    return i + 1;
}

void qsort(vector<int> &n, int l, int r) {
    if (l >= r) return;
    int mid = partition(n, l, r);
    qsort(n, l, mid - 1);
    qsort(n, mid + 1, r);
}

void QuickSort(vector<int> &nums) {
    int len = nums.size();
    qsort(nums, 0, len - 1);
}

//O(nlogn) stable
void msort(vector<int> &n, vector<int> &t, int l, int r) {
    if (r - l == 1) return;
    int mid = l + r >> 1, tmid = l + r >> 1, tl = l, i = l;
    msort(n, t, l, mid), mergeSort(n, t, mid, r);
    while (tl < mid || tmid < r) {
        if (tmid >= r || (tl < mid && n[tl] <= n[tmid]))
            t[i++] = n[tl++];
        else
            t[i++] = n[tmid++];
    }
    for (int i = l; i < r; i++)
        n[i] = t[i];
}
void MergeSort(vector<int> &nums) {
    int len = nums.size();
    vector<int> T(len);
    msort(nums, T, 0, len);
}