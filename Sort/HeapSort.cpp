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
void HeapSort(vector<int>& nums) {
    BuildHeap(nums);
    for (int i = nums.length() - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        AdjustHeap(nums, 0, i);
    }
}