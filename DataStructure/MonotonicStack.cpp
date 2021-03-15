vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> s;
    int len = T.size();
    vector<int> res(len);
    for (int i = 0; i < len; i++) {
        while (!s.empty() && T[i] >= T[s.top()]) {
            int pre = s.top();
            res[pre] = i - pre;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

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
    while (k) {
        s.pop();
        k--;
    }
    if (s.empty()) return "0";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}