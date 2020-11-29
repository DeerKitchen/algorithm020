/**
* 589. N叉树的前序遍历
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> nStack;
        nStack.push(root);
        Node* temp = nullptr;
        while(!nStack.empty()) {
            temp = nStack.top();
            nStack.pop();
            res.emplace_back(temp->val);
            for(int i=temp->children.size()-1;i>=0;--i)
                nStack.push(temp->children[i]);
        }
        return res;
    }
};