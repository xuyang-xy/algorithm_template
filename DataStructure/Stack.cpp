string decodeString(string s) {
    string res = "";
    int len = s.length();
    stack<int> nums;
    stack<string> strs;
    int tempn = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') tempn = tempn * 10 + int(s[i] - '0');
        else if (s[i] == '[') {
            nums.push(tempn);
            strs.push(res);
            tempn = 0;
            res = "";
        }
        else if (s[i] == ']') {
            int n = nums.top();
            nums.pop();
            string temps = strs.top();
            strs.pop();
            for (int j = 0; j < n; j++) temps += res;
            res = temps;
        }
        else res += s[i];
    }
    return res;
}