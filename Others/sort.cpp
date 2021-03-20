/*
快速排序 时间复杂度 O(nlogn)
最坏情况 O(n^2) 将升/降序数组排序为降/升序
相关题目： 求第k大
*/
int div(vector<int>& nums, int l, int r) {
    /*
    plain div
    */
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
int div(vector<int>& nums, int l, int r) {
    /*
    two-way div
    */
    int temp = rand() % (r - l + 1) + l;
    swap(nums[temp], nums[r]);
    int flag = nums[r];
    int i = l, j = r - 1;
    while (true) {
        while (i < r && nums[i] < flag) i++;
        while (j >= l && nums[j] > flag) j--;
        if (i >= j) break;
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    swap(nums[r], num[i]);
    return i;
}
void qsort(vector<int>& nums, int l, int r) {
    /*
    one-two-way div
    */
    if (l >= r) return;
    int mid = div(nums, l, r);
    qsort(nums, l, mid - 1);
    qsort(nums, mid + 1, r);
}
void qsort(vector<int>& nums, int l, int r) {
    /*
    three-way qsort
    */
    if (l >= r) return;
    int temp = rand() % (r - l + 1) + l;
    swap(nums[temp], nums[r]);
    int flag = nums[r];
    int lt = l - 1, gt = r, i = l;
    while (i < gt) {
        if (nums[i] < flag) {
            swap(nums[i], nums[lt + 1]);
            lt++;
            i++;
        }
        else if (nums[i] > flag) {
            swap(nums[i], nums[gt - 1]);
            gt--;
        }
        else i++;
    }
    swap(nums[r], num[gt]);//[l, lt] [lt+1, gt] [gt + 1, r]
    qsort(nums, l, lt);
    qsort(nums, gt + 1, r);
}
void sort(vector<int>& nums) {
    int len = nums.size();
    qsort(nums, 0, len - 1);
}
/*
堆排序 时间复杂度O(nlogn)
升序排序，基于大顶堆Key[i] >= Key[2i+1] && key >= key[2i+2]
相关题目：topk， 数据流中位数
*/
void AdjustHeap(vector<int>& nums, int root, int len) {
    int temp = root;
    int left = root * 2 + 1, right = root * 2 + 2;
    if (left < len && nums[left] > nums[temp]) temp = left;
    if (right < len && nums[right] > nums[temp]) temp = right;
    if (temp != root) {
        swap(nums[temp], nums[root]);
        AdjustHeap(nums, temp, len);
    }
}
void BuildHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        AdjustHeap(nums, i, len);
    }
}
void sort(vector<int>& nums) {
    int len = nums.length();
    BuildHeap(nums);
    for (int i = len - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        AdjustHeap(nums, 0, i);
    }
}
/*
归并排序 时间复杂度O(nlogn)
最好，最坏，平均都是O(nlogn);
相关题目：逆序对
*/
void merge(vector<int>& n, vector<int>& t, int l, int mid, int r) {
    int i = l, j = mid + 1, index = 0;
    while(i <= mid && j <= r) {
        if (n[i] <= n[j]) t[index++] = n[i++];
        else t[index++] = n[j++];
    }
    while (i <= mid) t[index++] = n[i++];
    while (j <= right) t[index++] = n[j++];
    index = 0;
    while(l <= r) n[l++] = t[inedx++];
}
void msort(vector<int>& n, vector<int>& t, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    msort(n, t, l, mid), msort(n, t, mid + 1, r);
    merge(n, t, l, mid, r);
}
void MergeSort(vector<int>& nums) {
    int len = nums.size();
    vector<int> T(len);
    msort(nums, T, 0, len);
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