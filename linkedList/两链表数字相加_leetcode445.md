[vector做法](# vector做法)

[stack做法](# stack做法)

其实用stack更直观，代码行数也更少

## vector做法

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1, v2, v3;
        ListNode* ret = new ListNode(0), * dum = ret;
        while (l1 != NULL) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }

        int n1 = v1.size(), n2 = v2.size(), i, j, c;
        for (i = n1 - 1, j = n2 - 1, c = 0; i >= 0 && j >= 0; i --, j --) {
            int cur = v1[i] + v2[j] + c;
            c = cur / 10;
            cur = cur % 10;
            v3.insert(v3.begin(), cur);
        }
        while (i >= 0) {
            int cur = v1[i] + c;
            c = cur / 10;
            cur = cur % 10;
            v3.insert(v3.begin(), cur);
            i --;
        }
        while (j >= 0) {
            int cur = v2[j] + c;
            c = cur / 10;
            cur = cur % 10;
            v3.insert(v3.begin(), cur);
            j --;
        }
        if (c) v3.insert(begin(v3), c);
        for (int i = 0; i < v3.size(); i ++) {
            ret->next = new ListNode(v3[i]);
            ret = ret->next;
        }
        return dum->next;

    }   
};
```

## stack做法(有个反转拼接的trick)

res = c + res

这样新的就做头

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* ret = NULL;
        int c = 0;
        while (s1.size() || s2.size() || c) {
            int cur = c;
            if (s1.size()) cur += s1.top(), s1.pop();
            if (s2.size()) cur += s2.top(), s2.pop();
            
            c = cur / 10;
            cur = cur % 10; 

            ListNode* nNode = new ListNode(cur);
            nNode->next = ret;
            ret = nNode;
        }
        return ret;
    }   
};
```

