/*
堆排序 时间复杂度O(nlogn)
升序排序，基于大顶堆Key[i] >= Key[2i+1] && key >= key[2i+2]
*/
void AdjustHeap(vector<int>& nums, int root, int len) {
    int tmp = root;
    int l = root * 2 + 1, r = root * 2 + 2;
    if (l < len && nums[l] > nums[tmp]) tmp = l;
    if (r < len && nums[r] > nums[tmp]) tmp = r;
    if (tmp != root) {
        swap(nums[tmp], nums[root]);
        AdjustHeap(nums, tmp, len);
    }
}
void BuildHeap(vector<int>& nums) {
    for (int i = nums.size() / 2 - 1; i >= 0; i--) {
        AdjustHeap(nums, i, nums.size());
    }
}
void HeapSort(vector<int>& nums) {
    BuildHeap(nums);
    for (int i = nums.length() - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        AdjustHeap(nums, 0, i);
    }
}

// 模板题
/*
topk
数据流中位数
*/
// leetcode 215 数组第k大
int findKthLargest(vector<int>& nums, int k) {
    // priority_queue<int> maxheap;
    // for (int i = 0; i < nums.size(); i++)
    //     maxheap.push(nums[i]);
    // for (int i = 1; i < k; i++)
    //     maxheap.pop();
    // return maxheap.top();
}