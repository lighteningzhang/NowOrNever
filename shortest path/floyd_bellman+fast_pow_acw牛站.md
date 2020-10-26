实际是bellman ford的思想，套了快速幂的框架。这题之后还需要更新其他做法。

```c++
#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 * 2 + 10;
int g[N][N], res[N][N];
int n, t, s, e, idx = 0;
void mul(int res[][N], int a[][N], int b[][N]) {
    static int tmp[N][N];
    memset(tmp, 0x3f, sizeof tmp);
    for (int k = 0; k < idx; k ++) {
        for (int i = 0; i < idx; i ++) {
            for (int j = 0; j < idx; j ++) {
                tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    memcpy(res, tmp, sizeof tmp);
}
void fast_pow() {
    memset(res, 0x3f, sizeof res);
    for (int i = 0; i < idx; i ++) res[i][i] = 0;
    while (n) {
        if (n & 1) mul(res, res, g);
        mul(g, g, g);
        n >>= 1;
    }
}
int main() {
    scanf("%d %d %d %d", &n, &t, &s, &e);
    unordered_map<int, int> ids;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < t; i ++) {
        int c, a, b;
        scanf("%d %d %d", &c, &a, &b);
        if (ids.count(a)) a = ids[a];
        else ids[a] = idx ++, a = ids[a];
        if (ids.count(b)) b = ids[b];
        else ids[b] = idx ++, b = ids[b];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    fast_pow();
    
    s = ids[s], e = ids[e];
    printf("%d\n", res[s][e]);
    return 0;
}
```

