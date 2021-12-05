vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int len = nums.size();
    deque<int> Q;
    for (int i = 0; i < len; i++) {
        while (!Q.empty() && nums[i] > nums[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
        if (i >= k - 1) {
            while (!Q.empty() && i - Q.front() + 1 > k) {
                Q.pop_front();
            }
            // cout<<nums[Q.front()]<<endl;
            res.push_back(nums[Q.front()]);
        }
    }
    return res;
}
