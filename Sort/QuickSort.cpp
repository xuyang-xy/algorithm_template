/*
快速排序 时间复杂度 O(nlogn)
最坏情况 O(n^2) 将升/降序数组排序为降/升序
相关题目： 求第k大
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