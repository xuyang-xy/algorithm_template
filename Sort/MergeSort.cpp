/*
归并排序 时间复杂度O(nlogn)
最好，最坏，平均都是O(nlogn)
相关题目：逆序对
*/
void merge(vector<int>& n, vector<int>& t, int l, int mid, int r) {
    int i = l, j = mid + 1, ind = l;
    while(i <= mid && j <= r) {
        if (n[i] <= n[j]) {
            t[ind++] = n[i++];
        }
        else t[ind++] = n[j++];
    }
    while (i <= mid) t[ind++] = n[i++];
    while (j <= r) t[ind++] = n[j++];
    ind = l;
    while(l <= r) n[l++] = t[ind++];
}
void sort(vector<int>& n, vector<int>& t, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort(n, t, l, mid), sort(n, t, mid + 1, r);
    merge(n, t, l, mid, r);
}
void MergeSort(vector<int>& nums) {
    int len = nums.size();
    vector<int> tmp(len);
    sort(nums, tmp, 0, len);
}

// 模板题
/*
剑指 Offer 51. 数组中的逆序对
*/
int merge(vector<int>& n, vector<int>& t, int l, int mid, int r) {
    int tmp_cnt = 0;
    int i = l, j = mid + 1, ind = l;
    while(i <= mid && j <= r) {
        if (n[i] <= n[j]) t[ind++] = n[i++];
        else {
            tmp_cnt +=(mid - i + 1);
            t[ind++] = n[j++];
        }
    }
    while(i <= mid) t[ind++] = n[i++];
    while(j <= r) t[ind++] = n[j++];
    ind = l;
    while(l <= r) n[l++] = t[ind++];
}
int cnt(vector<int>& n, vector<int>& t, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    int cnt_num = cnt(n, t, l, mid) + cnt(n, t, mid + 1, r);
    int mergecnt = merge(n, t, l, mid, r);
    return mergecnt;
}
int reversePairs(vector<int>& nums) {
    int len = nums.size();
    vector<int> tmp(len);
    int ans = cnt(nums, tmp, 0, nums.size() - 1);
    return ans;
}