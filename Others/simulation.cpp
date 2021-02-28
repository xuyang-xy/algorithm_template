vector<int> smallestK(vector<int>& arr, int k) {
    vector<int> res;
    if (k == 0) return res;
    int len = arr.size();
    priority_queue<int> Q;
    for (int i = 0; i < k; i++) Q.push(arr[i]);
    for (int i = k; i < len; i++) {
        if (arr[i] < Q.top()) {
            Q.pop();
            Q.push(arr[i]);
        }
    }
    for (int i = 0; i < k; i++) {
        res.push_back(Q.top());
        Q.pop();
    }
    return res;
}

int compareVersion(string version1, string version2) {
    int len1 = version1.length();
    int len2 = version2.length();
    int l1 = 0, l2 = 0;
    int num1 = 0, num2 = 0;
    while(l1 < len1 || l2 < len2) {
        while (l1 < len1 && version1[l1] != '.') {
            num1 = num1 * 10 + int(version1[l1] - '0');
            l1++;
        }
        while (l2 < len2 && version2[l2] != '.') {
            num2 = num2 * 10 + int(version2[l2] - '0');
            l2++;
        }
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        num1 = 0;
        num2 = 0;
        l1++;
        l2++;
    }
    return 0;
}

int findkth(vector<int>& a, vector<int>& b, int k) {
    int a_len = a.size();
    int b_len = b.size();
    int la, lb, size, topk;
    size = k;
    la = lb = topk = 0;
    while(size > 1) {
        if (la == a_len) return b[lb + size - 1];
        if (lb == b_len) return a[la + size - 1];
        int index_a = min(la + size / 2 - 1, a_len - 1);
        int index_b = min(lb + size / 2 - 1, b_len - 1);
        int mid_a = a[index_a];
        int mid_b = b[index_b];
        if (mid_a <= mid_b) {
            size -= (index_a - la + 1);
            la = index_a + 1;
        }
        else {
            size -= (index_b - lb + 1);
            lb = index_b + 1;
        }
    }
    if (la == a_len) topk = b[lb + size - 1];
    else if (lb == b_len) topk = a[la + size - 1];
    else topk = min(a[la], b[lb]);
    return topk;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size() + nums2.size();
    int k1 = (size + 1) / 2;
    int k2 = (size + 2) / 2;
    double k1_num = double(findkth(nums1, nums2, k1));
    double k2_num = double(findkth(nums1, nums2, k2));
    return (k1_num + k2_num) / 2.0;
}


int getnext(int num) {
    int res = 0;
    int temp = num;
    while (temp) {
        res += (temp % 10) * (temp% 10);
        temp /= 10;
    }
    return res;
}
bool isHappy(int n) {
    int slow = n;
    int fast = getnext(n);
    while (fast != 1 && fast != slow) {
        slow = getnext(slow);
        fast = getnext(getnext(fast));
    }
    return fast == 1;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    if (grid[x][y]) return 1;
    if (grid[x][y] == 0)
        grid[x][y] = 1;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret *= dfs(grid, nx, ny);
    }
    return ret;
}
int closedIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int ans = 0;
    if (m == 0) return ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0)
                if (dfs(grid, i, j)) ans++;
        }
    }
    return ans;
}

