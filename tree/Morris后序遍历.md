* 后序需要一个翻转操作从最右到当前进行输出
* 注意最后还要从root进行反转

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
    void getPath(TreeNode *root) {
        if (root == NULL) return;
        int sz = res.size();
        root = reverseRoot(root);
        while (root != NULL) res.push_back(root->val), root = root->right;
        reverseRoot(root);
    }
    TreeNode * reverseRoot(TreeNode * root) {
        TreeNode * pre = NULL, * nxt = NULL;
        while (root) {
            nxt = root->right;
            root->right = pre;
            pre = root;
            root = nxt;
        }
        return pre;
    }
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode* p = root;
        while (root != NULL) {
            TreeNode * nxt = root->left;
            if (nxt != NULL) {
                while (nxt->right != NULL && nxt->right != root) {
                    nxt = nxt->right;
                }
                if (nxt->right == NULL) {
                    nxt->right = root;
                    root = root->left;
                } else {
                    nxt->right = NULL;
                    getPath(root->left);
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        getPath(p);
        return res;
    }
};
```

