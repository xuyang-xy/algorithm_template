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
    int lt = l - 1, gt = r, i = l; // lt: <区的右边界 gt:>区的左边界
    while (i < gt) {
        if (nums[i] < flag) {
            lt++;
            swap(nums[lt], nums[i]);
            i++;
        }
        else if (nums[i] > flag) {
            gt--;
            swap(nums[gt], nums[i]);
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

// 模板题
/*
leetcode 75 颜色分类
基于三路划分实现 一次遍历 O(n)
*/
int div(vector<int>& num, int l, int r) {
    if (l >= r) return -1;
    int flag = 1, tl = l - 1, tr = r + 1;
    int index = l;
    while (index < tr) {
        if (num[index] < flag) {
            tl++;
            swap(num[tl], num[index]);
            index++;
        }
        else if (num[index] > flag) {
            tr--;
            swap(num[tr], num[index]);
        }
        else index++;
    } 
    return 0;
}
void sortColors(vector<int>& nums) {
    int ret = div(nums, 0, nums.size() - 1);
}
