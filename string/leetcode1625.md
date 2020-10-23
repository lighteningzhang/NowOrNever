https://leetcode-cn.com/problems/lexicographically-smallest-string-after-applying-operations/

本题蕴含的思想：

1. 分类讨论
2. 以静解动

在做这个题时，我比较担心的是移动和加的枚举空间和次序。解决这个担心的第一点，是考虑移动和加是否存在循环，也就是可能会出现**规律**，这样枚举空间会大大减小。第二个点是**分类讨论**, 也就是观察奇偶性，b在移动的时候奇数偶数的规律是不同的。第三个点是**以静解动**, 静态问题是加法，动态问题是移动，b为偶数的时候很容易看出，移动后再加和加后再移动是一致的。难点在b为奇数的情况，移动后加和加再移动完全不同（因只加在奇数位，移动后奇数位会变化），这也是本题较难的原因之一，但比较巧妙的做法是以静解动，其实无非就是奇数位和偶数位的运算，可以先对奇数位和偶数位都处理后再移动，这样的效果和移动后再进行奇数位和偶数位的操作是一致的。

```c++
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();

        string res = s;
        if (b % 2 == 0)
            for (int i = 0; i < n; i ++) {
                string tmp = s;
                for (int j = 0; j < 10; j ++) {
                    for (int k = 0; k < n; k ++) {
                        if (k % 2) {
                            s[k] = (s[k] - '0' + a) % 10 + '0';
                        }
                    }
                    res = min(res, s);
                }
                for (int t = 0; t < n; t ++) {
                    int nidx = (t + b) % n;
                    s[nidx] = tmp[t];
                }
                res = min(res, s);   
            }
        else {
            for (int i = 0; i < 10; i ++) {
                for (int k = 1; k < n; k += 2) s[k] = (s[k] - '0' + a) % 10 + '0';
                res = min(res, s);   

                for (int j = 0; j < 10; j ++) {
                    for (int k = 0; k < n; k += 2) s[k] = (s[k] - '0' + a) % 10 + '0';
                    for (int t = 0; t < n; t ++) {
                        res = min(res, s); 
                        string tmp = s;  
                        for (int t = 0; t < n; t ++) {
                            int nidx = (t + b) % n;
                            s[nidx] = tmp[t];
                            // 更高级的写法
                            // s = s.substr(n - b) + s.substr(0, n - b);
                        }
                    }
                   
                } 
            }
        }
        return res;
    }
};
```

而出题人想要的做法其实应该是bfs+set优化, 这个更直观也更容易操作和想到

```c++
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();

        string res = s;
        set<string> se;
        queue<string> q;
        q.push(s);
        se.insert(s);
        while (q.size()) {
            string cur = q.front();
            q.pop();
            string tmp = cur;
            for (int i = 1; i < n; i += 2) {
                cur[i] += a;
                if (cur[i] > '9') cur[i] -= 10;
            }
            if (se.find(cur) == se.end()) {
                q.push(cur);
                se.insert(cur);
                res = min(res, cur);
            }
            cur = tmp.substr(n - b) + tmp.substr(0, n - b);
            if (se.find(cur) == se.end()) {
                q.push(cur);
                se.insert(cur);
                res = min(res, cur);
            }
        }
        return res;
    }
};
```

