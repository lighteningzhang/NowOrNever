以前遇到的只有边权，没有点权，所以遇到这题不知道怎么处理，但一看到建立虚拟源点就秒懂了...

把点权看做源点0到该点的边权即可

```c++
// 有关联关系（建点和建边）
#include <bits/stdc++.h>

using namespace std;
int n, idx = 0;
const int N = 310 * 310 * 2;
struct E{
    int u, v, w;
    bool operator < (E & b) const {
        return w < b.w;
    }
}e[N];
int par[310];
int findp(int x) {
    return x == par[x] ? x : findp(par[x]);
}

bool uni(int x, int y) {
    x = findp(x);
    y = findp(y);
    if (x != y) {
        par[y] = x;
        return true;
    }
    return false;
}
int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        e[idx ++] = {0, i, x};
    }
    for (int i = 0; i <= n; i ++) par[i] = i;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            int x;
            scanf("%d", &x);
            e[idx ++] = {i, j, x};
        }
    }
    sort(e, e + idx);
    int cst = 0;
    for (int i = 0; i < idx; i ++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (uni(u, v)) cst += w;
    }
    printf("%d\n", cst);
    return 0;
}
```

