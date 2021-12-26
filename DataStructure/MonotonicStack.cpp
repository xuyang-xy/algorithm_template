vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    stack<int> s;
    for (int i = 0; i < temperatures.size(); i++) {
        while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int largestRectangleArea(vector<int>& heights) {
    int res = -1;
    int len = heights.size();
    vector<int> left_val(len, -1), right_val(len, len);
    stack<int> s;
    for (int i = 0; i < len; i++) {
        while(!s.empty() && heights[i] < heights[s.top()]) {
            right_val[s.top()] = s.empty()?len:i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = len - 1; i >= 0; i--) {
        while(!s.empty() && heights[i] < heights[s.top()]) {
            left_val[s.top()] = s.empty()?-1:i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < len; i++) {
        res = max(res, heights[i] *(right_val[i] - left_val[i] - 1));
        // printf("%d %d %d\n", heights[i], right_val[i], left_val[i]);
    }
    return res;
}

int trap(vector<int>& height) {
    int len = height.size();
    int res = 0;
    stack<int> s;
    for (int i = 0; i < len; i++) {
        while (!s.empty() && height[s.top()] < height[i]) {
            int tmp = height[s.top()];
            s.pop();
            if (s.empty()) break;
            res += (min(height[i], height[s.top()]) - tmp) * (i - s.top() - 1);
        }
        s.push(i);
    }
    return res;
}

class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        if (s.empty() || price < s.top().first) {
            s.push(pair(price, 1));
            return 1;
        }
        int res = 1;
        while(!s.empty() && price >= s.top().first) {
            res += s.top().second;
            s.pop();
        }
        s.push(pair(price, res));
        return res;
    }
};

string removeKdigits(string num, int k) {
    int len = num.length();
    if (len == 0) return "0";
    stack<char> s;
    string ans;
    for (int i = 0; i < len; i++) {
        while (!s.empty() && num[i] < s.top() && k) {
            s.pop();
            k--;
        }
        if (s.empty() && num[i] == '0') continue;
        s.push(num[i]);
    }
    while (!s.empty() && k) {
        k--;
        s.pop();
    }
    if (s.empty()) return "0";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}