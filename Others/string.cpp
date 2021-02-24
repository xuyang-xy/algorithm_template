// 构造最长回文串
int longestPalindrome(string s) {
    map<char, int> M;
    map<char, int>::iterator item;
    int len = s.length();
    int ans = 0, flag = 0;
    for (int i = 0; i < len; i++) {
        if (M.count(s[i]) == 0)
            M[s[i]] = 1;
        else M[s[i]]++;
    }
    for (item = M.begin(); item != M.end(); item++) {
        if (item->second % 2 == 0)
            ans += item->second;
        else {
            flag = 1;
            if (item->second > 1)
                ans += item->second - 1;
        }
    }
    return ans + flag;
}

// 最大回文子串
string longestPalindrome(string s) {
    int len = s.length();
    if (len <= 1) return s;
    const int maxn = 1005;
    int dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    int l = 0, ans = 1;
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    for (int i = len - 2; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                if (dp[i + 1][j - 1] || j == i + 1) {
                    dp[i][j] = 1;
                    if (j - i + 1 > ans) {
                        ans = j - i + 1;
                        l = i;
                    }
                }
            }
        }
    }
    string res = s.substr(l, ans);
    return res;
}

// 最大回文子序列
int longestPalindromeSubseq(string s) {
    int len = s.length();
    if (len <= 1) return len;
    const int maxn = 1005;
    int dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    for (int i = len - 2; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][len - 1];
}

// 最大无重复子串
int lengthOfLongestSubstring(string s) {
    int len = s.length();
    if (len <= 1) return len;
    map<char, int> vis;
    for (int i = 0; i < len; i++)
        vis[s[i]] = -1;
    int cur_len = 0, ans = 1;
    for (int i = 0; i < len; i++) {
        int index = vis[s[i]];
        vis[s[i]] = i;
        if (index < 0 || index + cur_len < i) {
            cur_len++;
        }
        else {
            ans = max(ans, cur_len);
            cur_len = i - index;
        }
    }
    ans = max(ans, cur_len);
    return ans;
}

// 最大重复子串
bool search(string& S, int len){
    unordered_set<string> st;
    for(int i = 0; i < S.size(); i++) {
        string temp = S.substr(i,len);
        if (st.count(temp)) return true;
        else st.insert(temp);
    }
    return false;
}
int longestRepeatingSubstring(string S) {
    int len = S.length();
    int l = 1, r = len, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (search(S, mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else r = mid - 1;
    }
    return ans;
}

// 最大子串和
int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    const int maxn = 3e4 + 5;
    int dp[maxn];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < len; i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

// 最长上升子序列
int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return len;
    const int maxn = 2505;
    int dp[maxn];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < len; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// 最大公共子序列
int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    if (len1 == 0 || len2 == 0) return 0;
    const int maxn = 1005;
    int dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}

string addStrings(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int flag = 0;
    string ans = "";
    for (int i = 1; i <= len1 || i <= len2; i++) {
        int add1 = i <= len1 ? int(num1[len1 - i] - '0') : 0;
        int add2 = i <= len2 ? int(num2[len2 - i] - '0') : 0;
        int add_num = (flag + add1 + add2) % 10;
        flag = (flag + add1 + add2) / 10;
        ans += ('0' + add_num);
    }
    if (flag) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

string minWindow(string s, string t) {
    string ans = "";
    int slen = s.length();
    int tlen = t.length();
    if (slen == 0 || tlen == 0) return ans;
    int l = 0, r = 0, ans_len = slen + 1;
    int cnt = 0;
    map<char, int> scnt, tcnt;
    for (int i = 0; i < tlen; i++) tcnt[t[i]]++;
    while (r < slen) {
        char temp_r = s[r];
        scnt[temp_r]++;
        if (tcnt.count(temp_r) && scnt[temp_r] <= tcnt[temp_r]) cnt++;
        while (l <= r && cnt == tlen) {
            if (r - l + 1 < ans_len) {
                ans_len = r - l + 1;
                ans = s.substr(l, ans_len);
            }
            char temp_l = s[l];
            scnt[temp_l]--;
            if (tcnt.count(temp_l) && scnt[temp_l] < tcnt[temp_l]) cnt--;
            l++;
        }
        r++;
    }
    return ans;
}