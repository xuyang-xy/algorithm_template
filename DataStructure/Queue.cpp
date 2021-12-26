class MaxQueue {
    queue<int> alldata;
    deque<int> maxdata;
public:
    MaxQueue() {
    }
    int max_value() {
        if (maxdata.empty()) return -1;
        else return maxdata.front();
    }
    void push_back(int value) {
        while (!maxdata.empty() && maxdata.back() < value) {maxdata.pop_back();}
        maxdata.push_back(value);
        alldata.push(value);
    }
    int pop_front() {
        if (alldata.empty()) return -1;
        int ans = alldata.front();
        if (ans == maxdata.front()) {maxdata.pop_front();}
        alldata.pop();
        return ans;
    }
};