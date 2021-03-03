class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {}
    void addNum(int num) {
        if (left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    double findMedian() {
        double res = left.size() > right.size() ? left.top() : (left.top() + right.top()) / 2.0;
        return res;
    }
};