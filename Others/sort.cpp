/*
快速排序 时间复杂度 O(nlogn)
最坏情况 O(n^2) 将升/降序数组排序为降/升序
*/
int div(vector<int>& nums, int l, int r) {
    int flag = nums[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (nums[j] < flag) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}
void qsort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = div(nums, l, r);
    qsort(nums, l, mid - 1);
    qsort(nums, mid + 1, r);
}
void sort(vector<int>& nums) {
    int len = nums.size();
    qsort(nums, 0, len - 1);
}








// O(n^2)
void BubbleSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j + 1 < len - i; j++) {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

// O(n^2)
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

// O(n^2)
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

// O(nlogn)
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

// O(nlogn)
int partition(vector<int> &n, int l, int r) {
    int temp = n[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (n[j] <= temp) {
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

// O(nlogn)
void msort(vector<int> &n, vector<int> &t, int l, int r) {
    if (r - l == 1) return;
    int mid = l + r >> 1, tmid = l + r >> 1, tl = l, index = l;
    msort(n, t, l, mid), msort(n, t, mid, r);
    while (tl < mid || tmid < r) {
        if (tmid >= r || (tl < mid && n[tl] <= n[tmid]))
            t[index++] = n[tl++];
        else
            t[index++] = n[tmid++];
    }
    for (int i = l; i < r; i++)
        n[i] = t[i];
}
void MergeSort(vector<int> &nums) {
    int len = nums.size();
    vector<int> T(len);
    msort(nums, T, 0, len);
}

// O(nlogn)
void AdjustHeap(vector<int> &n, int index, int len) {
    int max_index = i;
    int left = index * 2 + 1, right = index * 2 + 2;
    if (left < len && n[left] > n[index]) max_index = left;
    if (right < len && n[right] > n[index]) max_index = right;
    if (index != max_index) {
        swap(n[index], n[max_index]);
        AdjustHeap(n, max_index, len);
    }
}
void BuildHeap(vector<int> &n) {
    int len = n.size();
    for (int i = len / 2 - 1; i >= 0; i--)
        AdjustHeap(n, i, len);
}
void HeapSort(vector<int> &nums) {
    int len = nums.size();
    BuildHeap (nums);
    for (int i = len - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        AdjustHeap(nums, 0, i);
    }
}

// O(n)
void CountingSort(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) return;
    int Min = nums[0], Max = nums[0];
    for (int i = 1; i < len; i++) {
        Max = max(Max, nums[i]);
        Min = min(Min, nums[i]);
    }
    int bias = 0 - Min;
    vector<int> bucket(Max - Min + 1, 0);
    for (int i = 0; i < len; i++)
        bucket[a[i] + bias]++;
    int index = 0, i = 0;
    while (index < len) {
        if (bucket[i]) {
            a[index] = i - bias;
            bucket[i]--;
            index++;
        }
        else i++;
    }
}

// O(n)
void BucketSort(vector<int> &nums, int bucketSize) {
    int len = nums.size();
    if (len < 2) sreturn;
    int Min = nums[0], Max = nums[0];
    for (int i = 1; i < len; i++) {
        Max = max(Max, nums[i]);
        Min = min(Min, nums[i]);
    }
    int bucketCount = (Max - Min) / bucketSize + 1;
    vector<int> bucketArr[bucketCount];
    for (int i = 0; i < len; i++)
        bucketArr[(nums[i] - Min) / bucketSize].push_back(nums[i]);
    nums.clear();
    for (int i = 0; i < bucketCount; i++) {
        int tlen = bucketArr[i].size();
        sort(bucketArr[i].begin(),bucketArr[i].end());
        for (int j = 0; j < tlen; j++)
            nums.push_back(bucketArr[i][j]);
    }
}

// O(n)
void RadixSortSort(vector<int> &nums) {
    int len = nums.size();
    if (len < 2) return;
    int Max = nums[0];
    for (int i = 1; i < len; i++)
        Max = max(Max, nums[i]);
    int maxDigit = log10(Max) + 1;
    int mod = 10, div = 1;
    vector<int> bucketList[10];
    for (int i = 0; i < maxDigit; i++, mod *= 10, div *= 10) {
        for (int j = 0; j < len; j++) {
            int num = (nums[j] % mod) / div;
            bucketList[num].push_back(nums[j]);
        }
        int index = 0;
        for (int j = 0; j < 10; j++) {
            int tlen=bucketList[j].size();
            for (int k = 0; k < tlen; k++)
                nums[index++] = bucketList[j][k];
            bucketList[j].clear();
        }
    }
}