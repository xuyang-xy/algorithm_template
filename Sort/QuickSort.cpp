/*
快速排序的多种实现：
01. 基于固定基准划分的朴素实现
02. 基于随机选择基准的双路实现
03. 基于随机选择基准的三路实现
*/
int div(vector<int>& nums, int l, int r) {
    /*
    基于朴素划分的实现
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
    基于随机选取基准的双路划分
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
    swap(nums[i], nums[r]);
    return i;
}
void qsort(vector<int>& nums, int l, int r) {
    /*
    基于朴素快排与双路快排的实现
    */
    if (l >= r) return;
    int mid = div(nums, l, r);
    qsort(nums, l, mid - 1);
    qsort(nums, mid + 1, r);
}
void qsort(vector<int>& nums, int l, int r) {
    /*
    基于三路快排的实现
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
    swap(nums[gt], nums[r]);
    qsort(nums, l, lt);
    qsort(nums, gt + 1, r);
}
void sort(vector<int>& nums) {
    int len = nums.size();
    qsort(nums, 0, len - 1);
}

/*
leetcode 75 颜色分类
基于三路划分实现 一次遍历 O(n)
*/
void sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int lt = l - 1;
    int gt = r + 1;
    int i = l;
    while (i <= r && i < gt) {
        if (nums[i] < 1) {
            swap(nums[i], nums[lt + 1]);
            lt++;
            i++;
        }
        else if (nums[i] > 1) {
            swap(nums[i], nums[gt - 1]);
            gt--;
        }
        else i++;
    }
}
void sortColors(vector<int>& nums) {
    int len = nums.size();
    sort(nums, 0, len - 1);
}