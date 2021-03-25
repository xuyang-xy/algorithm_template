class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> Q;
    int len;
public:
    KthLargest(int k, vector<int>& nums) {
        len = k;
        for (int i = 0; i < nums.size(); i++) add(nums[i]);
    }
    
    int add(int val) {
        Q.push(val);
        if (Q.size() > len) Q.pop();
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */