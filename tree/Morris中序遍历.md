```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode * p = root;
        while (p != NULL) {
            
            TreeNode * cur = p->left;
            if (cur != NULL) {
                while (cur->right != NULL && cur->right != p) {
                    cur = cur->right;
                }
                if (cur->right == NULL) cur->right = p, res.push_back(p->val), p = p->left;
                else {
                    p = p->right;
                    cur->right = NULL;
                }       
            } else {
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};
```

