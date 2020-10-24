层次遍历

debug了10分钟，因为指针没初始化就送到if语句了..

```c++
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> q;
        q.push(root);
        if (d == 1) {
            TreeNode* dum = new TreeNode(v);
            dum->left = root;
            return dum;
        }
        int step = 1;
        while (q.size()) {
            int sz = q.size();
            // cout << step << endl;
            if (step == d - 1) {
                while (sz --) {
                    TreeNode* cur = q.front();
                    // cout << cur->val << endl;
                    q.pop();
                    TreeNode* l = NULL, * r = NULL;
                    if (cur->left)  
                        l = cur->left;
                    if (cur->right)
                        r = cur->right;
                    TreeNode* addl = new TreeNode(v), * addr = new TreeNode(v);
                    cur->left = addl;
                    cur->right = addr;
                    if (l)  addl->left = l;
                    if (r)  addr->right = r;
                    
                }
                return root;
            }
            else {
                while (sz --) {
                    TreeNode* cur = q.front();
                    q.pop();
                    if (cur->left)  
                        q.push(cur->left);
                    if (cur->right)
                        q.push(cur->right);
                }
            }
            step ++;
        }
        return root;
    }
};
```

