- [三指针 + 简单组合计数](#head1)
- [ 线性dp](#head2)
## <span id="head1">三指针 + 简单组合计数</span>

看了别人的题解，这题竟然还可以用**状态转移**来做...该解法附到后面

刚开始没什么思路，还是考虑的hashset find，找到三个元素的个数，但这样会重复算，然后思维就陷进去了

后来看了下题解标题，发现可以用三指针做，但考虑的i, j, k 是i, j 指向头，k 指向尾，这样在sum < target的时候移动就会存在问题了(是移i还是j?)

这里思路上的一个提示，三指针的时候，一般其中的两个指针一个指向头，一个指向尾，这样好移动。

第一个指针指向当前元素

双指针j, k分别指向 0 和 n - 1

虽然之前碰到过类似的，但又忘了

```c++
class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        int n = a.size(), res = 0;
        sort(begin(a), end(a));
        for (int i = 0; i < n; i ++) {
            int j = i + 1, k = n - 1;
            int t = target - a[i];
            while (j < k) {
                int sum = a[j] + a[k];
                if (sum > t) {
                    k --;
                } else if (sum < t) {
                    j ++;
                } else {
                    // res = (res + 1) % 1000000007;
                    if (a[j] == a[k]) {
                        res = (res + (k - j + 1) * (k - j) / 2) % 1000000007;
                        break;
                    }
                    else {
                        int cnt1 = 1, cnt2 = 1;
                        while (a[j] == a[j + 1]) j ++, cnt1 ++;
                        j ++;
                        while (a[k] == a[k - 1]) k --, cnt2 ++;
                        k --;
                        res = (res + cnt1 * cnt2) % 1000000007;
                        // cout << a[i] << " " << i << " " << cnt1 << " " << cnt2 << endl;
                    }
                }
            }
        }
        return res;
    }
};
```

## <span id="head2"> 线性dp</span>

```c++
class Solution {
public:

    int threeSumMulti(vector<int>& a, int target) {
        const int mod = 1000000007;
        int n = a.size(), res = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (4, vector<int>(target + 1)));
        for (int i = 0; i < n; i ++)
            dp[i][0][0] = 1; //可以从当前元素开始选
        // O(3000 * 3 * 300)
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) {
                for (int k = 0; k <= target; k ++) {
                    if (k >= a[i - 1]) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - a[i - 1]]) % mod;
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % mod;
                }

            }
        }
        return dp[n][3][target];
    }
};
```