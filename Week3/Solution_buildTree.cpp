/**
 * 105. 从前序与中序遍历序列构造二叉树
 * 1、循环加递归的思路
 * 2、使用hash表保存中序遍历的元素及其位置。
 */
class Solution {
    unordered_map<int, int> mp;
    int idx = 0, n;
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        n = in.size();
        for (int i = 0; i < n; ++i) mp[in[i]] = i;
        return bt(pre, 0, n - 1);
    }

    TreeNode* bt(vector<int>& pre, int l, int r) {
        if (l > r) return nullptr; //结束条年
        int i = mp[pre[idx]];

        TreeNode* root = new TreeNode(pre[idx++]); //生成根节点
        root->left = bt(pre, l, i - 1); //建立左子树
        root->right = bt(pre, i + 1, r);//建立右子树
        return root;
    }
};
