核心公式:

$$2^k = 2^{k - 1} + 2^{k - 1}$$

对应:

$$f[i][k] = f[f[i][k - 1]][k - 1]$$

```c++
#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 4 * 1e4 + 10, M = 2 * N;
int h[N], e[M], nxt[M], idx;
int fa[N][16];

void add(int u, int v) {
    e[idx] = v;
    nxt[idx] = h[u];
    h[u] = idx ++;
}

int depth[N];

void dfs(int root) {
    for (int i = 1; i <= 15; i ++) {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    for (int i = h[root]; ~i; i = nxt[i]) {
        int j = e[i];
        if (j == fa[root][0]) continue;
        fa[j][0] = root;
        depth[j] = depth[root] + 1; 
        // cout << "depth: " << depth[j] << " " << j << endl;
        dfs(j);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    for (int i = 15; ~i; i --) {
        if (depth[fa[x][i]] >= depth[y])   x = fa[x][i];
    }
    // cout << "x: " << x << " y: " << y << endl;
    if (x == y) return x;
    
    for (int i = 15; i >= 0; i --) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
int main () {
    scanf("%d", &n);
    int root;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b ^ -1) {
            add(a, b);
            add(b, a);
        } else {
            root = a;
        }
    }
    fa[root][0] = 0;
    depth[root] = 1;
    dfs(root);
    scanf("%d", &m);
    while (m --) {
        int a, b;
        scanf("%d %d", &a, &b);
        int p = lca(a, b);
        // cout << p << endl;
        if (p == a) puts("1");
        else if (p == b) puts("2");
        else puts("0");
    }
    return 0;
}
```

