/**
*  二叉树的最近公共祖先
*  1、该题使用递归法的思想，易于理解;
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root; //结束条件
        auto leftFather = lowestCommonAncestor(root->left,p,q); //进入下一层
        auto rightFather = lowestCommonAncestor(root->right,p,q); //进入下一层
        if(!leftFather) return rightFather; //处理当前层逻辑
        if(!rightFather) return leftFather; //处理当前层逻辑
        return root;
    }
};
