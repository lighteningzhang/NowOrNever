## 题目

lc 941

## 滑动窗口求最小值模板

```c++
int q[N], hh = 0, tt = -1;
for (int i = 0; i < n; i ++) {
    if (i - q[hh] + 1 > k) hh ++;
    while (hh <= tt && a[q[tt]] > a[i]) tt --;
    q[++ tt] = i;
    if (i >= k - 1) printf("%d ", a[q[hh]]);
}
```

