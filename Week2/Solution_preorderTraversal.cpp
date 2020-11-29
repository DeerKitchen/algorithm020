/**
 *  144. 二叉树的前序遍历
 */
//递归法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return preVec;
        preVec.emplace_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preVec;
    }
private:
    vector<int> preVec;
};

//迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode* > preStk;
        vector<int> preVec;
        TreeNode* current = root;
        while(current || preStk.size()) {
            while(current) {
                preStk.push(current->right);
                preVec.emplace_back(current->val);
                current = current->left;
            }
            current = preStk.top();
            preStk.pop();
        }
        return preVec;
    }
};