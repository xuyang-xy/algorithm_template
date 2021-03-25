/*
二叉树翻转 递归非递归 O(n)
*/
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* nleft = invertTree(root->left);
    TreeNode* nright = invertTree(root->right);
    root->left = nright;
    root->right = nleft;
    return root;
}
TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()) {
        TreeNode* temp = Q.front();
        Q.pop();
        swap(temp->left, temp->right);
        if (temp->left) Q.push(temp->left);
        if (temp->right) Q.push(temp->right);
    }
    return root;
}
/*
二叉树上下翻转
*/
TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || !root->left) return root;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    TreeNode* nroot = upsideDownBinaryTree(l);
    l->left = r;
    l->right = root;
    root->left = nullptr;
    root->right = nullptr;
    return nroot;
}


void preorder(vector<int>& res, TreeNode* n) {
    if (!n) return;
    res.push_back(n->val);
    preorder(res, n->left);
    preorder(res, n->right);
}
vector<int> preorderTraversal(TreeNode* n) {
    vector<int> res;
    stack<TreeNode*> s;
    s.push(n);
    while (!s.empty()) {
        TreeNode* temp = s.top();
        res.push_back(temp->val);
        s.pop();
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }
    return res;
}

void inorder(vector<int>& res, TreeNode* n) {
    if (!n) return;
    inorder(res, n->left);
    res.push_back(n->val);
    inorder(res, n->right);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* n = root;
    while(n != nullptr || !s.empty()) {
        if (n != nullptr) {
            s.push(n);
            n = n->left;
        }
        else {
            n = s.top();
            res.push_back(n->val);
            s.pop();
            n = n->right;
       }
    }
    return res;
}

void postorder(vector<int>& res, TreeNode* n) {
    if (!n) return;
    postorder(res, n->left);
    postorder(res, n->right);
    res.push_back(n->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> s, output;
    TreeNode* n = root;
    s.push(n);
    while (!s.empty()) {
        TreeNode* temp = s.top();
        output.push(temp);
        s.pop();
        if (temp->left) s.push(temp->left);
        if (temp->right) s.push(temp->right);
    }
    while (!output.empty()) {
        res.push_back(output.top()->val);
        output.pop();
    }
    return res;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            TreeNode* n = Q.front();
            Q.pop();
            temp.push_back(n->val);
            if (n->left) Q.push(n->left);
            if (n->right) Q.push(n->right);
        }
        res.push_back(temp);
    }
    return res;
}

TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    TreeNode* nright = invertTree(root->left);
    TreeNode* nleft = invertTree(root->right);
    root->left = nleft;
    root->right = nright;
    return root;
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int minDepth(TreeNode* root) {
    if (!root) return 0;
    int l_deep = minDepth(root->left);
    int r_deep = minDepth(root->right);
    if (l_deep * r_deep == 0) return max(l_deep, r_deep) + 1;
    else return min(l_deep, r_deep) + 1;
}

int dfs(TreeNode* n, int& sum) {
    if (!n) return 0;
    int l_val = dfs(n->left, sum);
    int r_val = dfs(n->right, sum);
    int temp = max(max(l_val + n->val, r_val + n->val), n->val);
    sum = max(sum, max(temp, n->val + l_val + r_val));
    return temp;
}
int maxPathSum(TreeNode* root) {
    const int INF = 1e8;
    int res = -INF;
    dfs(root, res);
    return res;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || p == root || q == root) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (!l) return r;
    if (!r) return l;
    return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while((root->val - p->val) * (root->val - q->val) > 0)
        root = p->val < root->val ? root->left : root->right;
    return root;
}

int dfs(TreeNode* n, int& flag) {
    if (!n) return 0;
    int l = dfs(n->left, flag);
    int r = dfs(n->right, flag);
    int change = max(l, r) - min(l, r) <= 1 ? 1 : 0;
    flag *= change;
    return max(l, r) + 1;
}
bool isBalanced(TreeNode* root) {
    int flag = 1;
    dfs(root, flag);
    return flag;
}

int dfs(TreeNode* n, int& len) {
    if (!n) return 0;
    int l = dfs(n->left, len);
    int r = dfs(n->right, len);
    int h = max(l, r) + 1;
    len = max(len, l + r + 1);
    return h;
}
int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int len = -1;
    dfs(root, len);
    return len - 1;
}

int numTrees(int n) {
    const int maxn = 1e3;
    int dp[maxn];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];
    }
    return dp[n];
}

bool check(TreeNode* a, TreeNode* b) {
    if (!b) return true;
    if (!a) return false;
    if (a->val != b->val) return false;
    return (check(a->left, b->left) && check(a->right, b->right));
}
bool dfs(TreeNode* a, TreeNode* b) {
    if (!a) return false;
    if (check(a, b)) return true;
    else return (dfs(a->left, b) || dfs(a->right, b));
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!A || !B) return false;
    bool res = dfs(A, B);
    return res;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return targetSum == root->val;
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}