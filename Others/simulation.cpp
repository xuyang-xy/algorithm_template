/*
001. 两数之和
利用map以O(1)进行查询，时间复杂度O(n) 空间复杂度O(n)
朴素的双重循环时间复杂度O(n^2) 空间复杂度O(1)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int len = nums.size();
    if (len == 0) return res;
    map<int, int> m;
    for (int i = 0; i < len; i++) {
        if (m.count(nums[i]) == 0) {
            m[nums[i]] = i;
        }
    }
    for (int i = 0; i < len; i++) {
        if (m.count(target - nums[i]) && m[target - nums[i]] != i) {
            res = {i, m[target - nums[i]]};
            break;
        }
    }
    return res;
}
/*
015. 三数之和
固定一个数后用双指针遍历右端元素 时间复杂度O(n^2)
朴素三重循环时间复杂度O(n^3)
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int len = nums.size();
    if (len == 0) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;
        int l = i + 1;
        int r = len - 1;
        while (l < r) {
            int temp = nums[i] + nums[l] + nums[r];
            if (temp == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l + 1 < r && nums[l] == nums[l + 1]) l++;
                while (r - 1 > l && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            }
            else if (temp < 0) l++;
            else r--;
        }
    }
    return res;
}
/*
215. 数组中第K大
01. 基于快排划分的分治 最坏O(n^2) 期望为O(n)
02. 基于大根堆，删去K- 1 次堆顶 O(nlogn)
*/
int div(vector<int>& nums, int l ,int r) {
    int i = l - 1;
    int flag = nums[r];
    for (int j = l; j < r; j++) {
        if (nums[j] < flag) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}
int findKth(vector<int>& nums, int l ,int r, int index) {
    int mid = div(nums, l, r);
    if (mid == index) return nums[mid];
    else if (mid < index) return findKth(nums, mid + 1, r, index);
    else return findKth(nums, l, mid - 1, index);
}
int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    int kth = len - k;
    int res = findKth(nums, 0, len - 1, kth);
    return res;
}
void AdjustHeap(vector<int>& nums, int root, int len) {
    int temp = root;
    int left = temp * 2 + 1, right = temp * 2 + 2;
    if (left < len && nums[temp] < nums[left]) temp = left;
    if (right < len && nums[temp] < nums[right]) temp = right;
    if (temp != root) {
        swap(nums[temp], nums[root]);
        AdjustHeap(nums, temp, len);
    }
}
void BuildHeap(vector<int>&nums, int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        AdjustHeap(nums, i, len);
}
int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    BuildHeap(nums, len);
    for (int i = 0; i < k - 1; i++) {
        swap(nums[0], nums[len - 1 - i]);
        AdjustHeap(nums, 0, len - 1 - i);
    }
    return nums[0];
}



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

void dfs (int index, int len, string t, string d, map<char, string>& m, vector<string>& res) {
    if (index == len) {
        res.push_back(t);
        return;
    }
    for (int i = 0; i < m[d[index]].length(); i++) {
        string nt = t + m[d[index]][i];
        dfs(index + 1, len, nt, d, m, res);
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> res;
    int len = digits.length();
    if (len == 0) return res;
    map<char, string> M{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    dfs(0, len, "", digits, M, res);
    return res;
}

int quickSelect(vector<int>& a, int l, int r, int index) {
    int q = randomPartition(a, l, r);
    if (q == index) {
        return a[q];
    } else {
        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }
}

inline int randomPartition(vector<int>& a, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(a[i], a[r]);
    return partition(a, l, r);
}

inline int partition(vector<int>& a, int l, int r) {
    int x = a[r], i = l - 1;
    for (int j = l; j < r; ++j) {
        if (a[j] <= x) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int findKthLargest(vector<int>& nums, int k) {
    srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
}

vector<int> smallestK(vector<int>& arr, int k) {
    vector<int> res;
    int len = arr.size();
    if (len == 0) return res;
    priority_queue<int> Q;
    for (int i= 0; i < k; i++) Q.push(arr[i]);
    for (int i = k; i < len; i++) {
        if (arr[i] < Q.top()) {
            Q.pop();
            Q.push(arr[i]);
        }
    }
    for(int i = 0; i < k; i++) {
        res.push_back(Q.top());
        Q.pop();
    }
    return res;
}

int div(vector<int>& n, int l, int r) {
    int flag = n[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (n[j] < flag) {
            i++;
            swap(n[i], n[j]);
        }
    }
    swap(n[i + 1], n[r]);
    return i + 1;
}
int findkth(vector<int>& n, int l, int r, int index) {
    int f = div(n, l, r);
    if (f == index) return n[index];
    else if (f < index) return findkth(n, f + 1, r, index);
    else return findkth(n, l, f - 1, index);
}
int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    int res = findkth(nums, 0, len - 1, len - k);
    return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
    if (right < 0 || down < 0) return res;
    while (left <= right && up <= down) {
        for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
        for (int i = up + 1; i <= down; i++) res.push_back(matrix[i][right]);
        if (left < right && up < down) {
            for (int i = right - 1; i >= left; i--) res.push_back(matrix[down][i]);
            for (int i = down - 1; i >= up + 1; i--) res.push_back(matrix[i][left]);
        }
        left++;
        right--;
        up++;
        down--;
    }
    return res;
}

int maxArea(vector<int>& height) {
    int ans = -1;
    int len = height.size();
    int l = 0, r = len - 1;
    while (l < r) {
        int temp = (r - l) * min(height[l], height[r]);
        ans = max(ans, temp);
        if (height[l] < height[r]) l++;
        else r--;
    }
    return ans;
}

void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    int l, r;
    for (int i = len - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            l = i;
            break;
        }
    }
    if (l >= 0) {
        for (int i = len - 1; i > l; i--) {
            if (nums[i] > nums[l]) {
                r = i;
                break;
            }
        }
        swap(nums[l], nums[r]);
    }
    reverse(nums.begin() + l + 1, nums.end());
}

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