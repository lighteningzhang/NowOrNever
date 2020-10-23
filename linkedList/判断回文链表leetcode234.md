https://leetcode-cn.com/problems/palindrome-linked-list/

本题依然是快慢指针的设定问题，比较好的设定应该判断**快指针**到fast->next->next，保证快指针是慢指针脚步的两倍，假设链表长度为n，快指针走的步数必然是慢指针的两倍, 2 x sl = fa, 节点数分别为 **fa + 1, sl + 1**。以下有两种情况：**fa + 1 == l, fa + 1 == l - 1**, 第一种相当于 2 x sl + 1 = len, 那么有 sl + 1 = (len + 1)/2, len为奇数，慢指针走过的节点必然是总节点数的一半，慢指针刚好在正中；第二种相当于 2 x sl + 2 = l, 有 sl + 1 = l/2, slow点走过的节点数，len为偶数，在偏左的正中

```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, * slow = head;
        // a b c 
        if (head == NULL) return true;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        slow = reverse(slow);
        while (slow != NULL) {
            if (head->val != slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL, *nxt;
        while (head != NULL) {
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
};
```

