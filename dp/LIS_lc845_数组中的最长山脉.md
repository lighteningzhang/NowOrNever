- [ 最长上升子序列](#head1)
- [ 正解](#head2)
一开始以为是最长上升子序列问题，写了O(n)复杂度的方法，爆炸，实际是要求连续。

复习了一个点：最长上升子序列O(n)做法，二分是**向上取整**（因为利用r - 1）当下的元素如果到达r的位置，那它必然处于子序列末尾（严格大于最后的元素）len++。

## <span id="head1"> 最长上升子序列</span>

```c++
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector <int> dp1(n), dp2(n);
        vector <int> ar1(n + 1, 0), ar2(n + 1, 0);
        if (n <= 2) return 0;
        for (int i = 0, len = 0; i < n; i ++) {
            dp1[i] = 1;
            int l = 0, r = len;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if (ar1[mid] < A[i]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (r + 1 > len) len ++;
            ar1[r + 1] = A[i];
            dp1[i] = r + 1;
            // cout << dp1[i] << endl;
        }
        for (int i = n - 1, len = 0; i >= 0; i --) {
            dp2[i] = 1;
            int l = 0, r = len;
            while(l < r) {
                int mid = l + r + 1>> 1;
                if (ar2[mid] < A[i]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (r + 1 > len) len ++;
            ar2[r + 1] = A[i];
            dp2[i] = r + 1;
            // cout << dp2[i] << endl;
        }

        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (dp2[i] > 1 && dp1[i] > 1)
                ans = max(ans, dp1[i] + dp2[i] - 1);
        }
        return ans;
    }
};
```



## <span id="head2"> 正解</span>

```c++
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector <int> dp1(n);
        if (n <= 2) return 0;
        dp1[0] = 1;
        for (int i = 1, cnt = 1; i < n; i ++) {
            if (A[i] > A[i - 1]) cnt ++, dp1[i] = cnt;
            else {
                cnt = 1;
                dp1[i] = 1;
            }
        }
        int ans = 0;
        for (int i = n - 2, cnt = 1; i > -1; i --) {
            if (A[i] > A[i + 1]) {
                if (dp1[i] ^ 1)
                    ans = max(ans, dp1[i] + cnt);
                cnt ++;
            } 
            else {
                cnt = 1;
            }
        }
        return ans;
    }
};
```