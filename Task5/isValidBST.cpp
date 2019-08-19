/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        long front=LONG_MIN;
        stack<TreeNode*> st;
        TreeNode *p=root;
        while(!st.empty()||p)
        {
            //边入栈边比较
            if(p)
            {
                st.push(p);
                p=p->left;
            }
            else
            {
                p=st.top();
                if(p->val<=front) return false;
                front=p->val;
                st.pop();
                p=p->right;
            }
        }
        return true;

    }
};
