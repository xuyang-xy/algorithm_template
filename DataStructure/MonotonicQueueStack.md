# 单调栈/单调队列
## 1. 单调队列
概述：呈单调性的队列；用于维护区间极值， 时间复杂度为O(n)，n为序列的元素个数  
构造：基于双端队列实现/数组模拟实现，由更新和查询两个操作组成:  
（1）更新，即维护单调性，新元素入队，从队尾开始删除影响单调性的元素，从队头开始，删除不在当前区间内的元素  
（2）查询：取出队列头部  
模板 基于stl实现维护区间最小值的单调队列  
```cpp
class MonotonicQueue {
private:
    deque<int> qdata;
public:
    void push(int val) {
        while (!qdata.empty() && qdata.back() > val) qdata.pop_back();
        qdata.push_back(val);
    }
    void pop(int val) {if (!qdata.empty() && qdata.front() == val) qdata.pop_front()}
    int query() {return qdata.front();}
};
vector<int> res;
MonotonicQueue MQ;
for (int i = 0; i < nums.size(); i++) {
    if (i < k) {
        MQ.push(nums[i]);
        if (i == k - 1) {
            res.push_back(MQ.query());
        } 
    }
    else {
        MQ.push(nums[i]);
        MQ.pop(nums[i - k]);
        res.push_back(MQ.query());
    }
}
return res;
```
模板 基于数组实现维护区间最小值的单调队列  
```cpp
int dq[maxn];
vector<int> res;
int h = 0, t = -1;
for (int i = 0; i < nums.size(); i++) {
    if (t >= h && i - dq[h] + 1 > k) h++;
    while (t >= h && nums[dq[t]] >= nums[i]) t--;
    qd[++t] = i;
    if (i >= k - 1) res.push_back(nums[dq[h]]);
}
return res;
```

## 2. 单调栈
概述：呈单调性的栈；用于维护序列中的"相邻大小"关系， 时间复杂度为O(n)，n为序列的元素个数  
构造：基于朴素栈实现，由更新和查询两个操作组成:  
(1) 更新：即维护单调性，基于待入栈元素，从栈顶开始删除影响单调性的元素，从队头开始  
(2) 查询：取出栈顶，为待入栈元素左边第一个更大(小顶栈)更小(大顶栈)元素  
(3) 更新：元素压栈  
模板 单调栈实现下一个更大数  
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res;
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] >= s.top()) s.pop();
        res.push_back(s.empty() ? -1 : s.top());
        s.push(nums[i]);
    }
    return res;
}
vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> s;
    vector<int> res;
    for (int i = 0; i < T.size(); i++) {
        // [73]
        // [74] 73
        // [75] 74
        // [75 71]
        // [75 71 69]
        // [75 72] 69 71
        // [76] 72 75
        // [76 73] 
        // 底-》顶 递减栈
        while (!s.empty() && T[i] > T[s.top()]) {
            int pre = s.top();
            res[pre] = i - pre;
            s.pop();
        }
        s.push(i);
    }
    return res;
}
```
相关题目：  
```
(1) Leetcode 739. 每日温度
(2) Leetcode 084. 矩阵图中最大矩形
(3) 
(4) 
(5) 
(6) 
```
