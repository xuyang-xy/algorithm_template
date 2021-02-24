void preorder(vector<int>& res, TreeNode* n) {
    if (!n) return;
    res.push_back(n->val);
    preorder(res, n->left);
    preorder(res, n->right);
}
void inorder(vector<int>& res, TreeNode* n) {
    if (!n) return;
    inorder(res, n->left);
    res.push_back(n->val);
    inorder(res, n->right);
}
void postorder(vector<int>& res, TreeNode* n) {
    if (!n) return;
    postorder(res, n->left);
    postorder(res, n->right);
    res.push_back(n->val);
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