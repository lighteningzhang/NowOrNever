1. 从多少点出发可以到达所有点(ind == 0的点)

2. 需要添加的边为max(p, q), p为ind == 0的点，q为outd == 0的点

注意：如果只有一个强连通分量，则(此时入度和出度都为0，但不需要加边)需要特判

```c++
#include <bits/stdc++.h>


using namespace std;
int n;
const int N = 110, M = N * N;
int num[N], low[N], id[N], stk[N], top = 0, scc_cnt = 0, dfn = 0;
int h[N], e[M], nxt[M], idx = 0;
void add (int u, int v) {
    e[idx] = v;
    nxt[idx] = h[u];
    h[u] = idx ++;
}
int tarjan(int u) { 
    num[u] = low[u] = ++ dfn;
    stk[top ++] = u;
    for (int i = h[u]; ~i; i = nxt[i]) {
        int j = e[i];
        if (!num[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (!id[j]) {
            low[u] = min(low[u], num[j]);
        }
    }
    if (num[u] == low[u]) {
        int y;
        ++ scc_cnt;
        do {
            y = stk[-- top];
            id[y] = scc_cnt;
        } while (y != u);
    }
}
int ind[N], outd[N];
int main () {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++) {
        int x;
        while (scanf("%d", &x), x) {
            add(i, x);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (!num[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = h[i]; ~j; j = nxt[j]) {
            int k = e[j];
            if (id[i] == id[k]) continue;
            outd[id[i]] ++, ind[id[k]] ++;
        }
    }
    int sm = 0, p = 0, q = 0;
    for (int i = 1; i <= scc_cnt; i ++) {
        if (!ind[i]) sm ++, p ++;
        if (!outd[i]) q ++;
    }
    printf("%d\n", sm);
    if (scc_cnt == 1) puts("0");
    else printf("%d\n", max(q, p));
    return 0;
}
```