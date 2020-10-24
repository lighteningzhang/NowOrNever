#### [累加数](https://leetcode-cn.com/problems/additive-number/)

其实主要就难在构造上，然后注意不要有前导0的问题出现

下次注意考虑用index实现，可能快些

```c++
class Solution {
public:
    bool eq(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 < max(n1, n2)) return false;
        for (int i = n1 - 1, j = n2 - 1, k = n3 - 1, c = 0; i >= 0 || j >= 0 || c; j --, i --, k --) {
            int cur = c;
            if (i >= 0) cur += s1[i] - '0';
            if (j >= 0) cur += s2[j] - '0';
            c = cur / 10;
            cur = cur % 10;
            if (cur != s3[k] - '0') return false;
            if (k == 0) return true;
        }
        return false;
    }
    
    bool check(string num, int cursz, string s1, string s2, int u) {
        int n = num.size(), n1 = s1.size(), n2 = s2.size(), mx = max(n1, n2);
        if (u >= 2) {
            for (int i = cursz; i < n; i ++) {
                if (i - (cursz) + 1 < mx)
                    continue;
                if (num[cursz] == '0' && i > cursz) return false;
                string test = num.substr(cursz, i - cursz + 1);
                // cout << s1 << " " << s2 << " " << test << endl;

                if (!eq(s1, s2, test)) continue;
                if (i == n - 1) return true;
                if (check(num, i + 1, s2, test, u + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (u == 0) {
                for (int i = 0; i < n; i ++) {
                    if (num[0] == '0' && i > 0) return false;
                    string s1 = num.substr(0, i + 1);
                    if (check(num, i - 0 + 1, s1, s2, u + 1)) {
                        return true;
                    }
                }
            } else {
                for (int i = n1; i < n; i ++) {
                    if (num[n1] == '0' && i > n1) return false;
                    string s2 = num.substr(n1, i - n1 + 1);
                    if (check(num, i + 1, s1, s2, u + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (check(num, 0, "", "", 0)) return true;
        return false;
    }
};
```

