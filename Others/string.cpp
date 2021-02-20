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

int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    if (len1 == 0 || len2 == 0) return 0;
    const int maxn = 1005;
    int dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    int flag = 0;
    for (int i = 0; i < len2; i++) {
        if (flag) dp[0][i] = 1;
        else if (text2[i] == text1[0]) {
            flag = 1;
            dp[0][i] = 1;
        }
    }
    flag = 0;
    for (int i = 0; i < len1; i++) {
        if (flag) dp[i][0] = 1;
        else if (text1[i] == text2[0]) {
            flag = 1;
            dp[i][0] = 1;
        }
    }
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1 - 1][len2 - 1];
}