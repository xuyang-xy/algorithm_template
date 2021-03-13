bool isValid(string s) {
    int len = s.length();
    if (len == 0) return true;
    map<char, char> pairs{
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
    stack<char> lefts;
    for (int i = 0; i < len; i++) {
        if (pairs.count(s[i])) lefts.push(s[i]);
        else {
            if (lefts.empty() || s[i] != pairs[lefts.top()]) return false;
            else lefts.pop();
        }
    }
    return lefts.size() == 0;
}