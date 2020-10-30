tarjan主要步骤：

1. 对点编号
2. 处理回退边
3. 将点划分到连通块，对连通块编号

该题难点：把题意转换为出度为0的点的连通块的size。在统计的时候，需要对每条边进行统计，判断边的两点是否属于同一个连通块，不是则一个连通块的出度会增加。

最后再对所有连通块进行统计。

```c++
#include <bits/stdc++.h>

using namespace std;

int n, m, scid;
const int N = 1e4 + 10, M = 5 * 1e4 + 10;
int low[N], num[N], stk[N], id[N], sz[N];
int h[N], e[M], nxt[M], idx = 0;    
int dout[N];

int dfn = 0, scc_cnt = 0, top = 0;
void add(int u, int v) {
    e[idx] = v;
    nxt[idx] = h[u];
    h[u] = idx ++;
}
void tarjan(int u) {
    low[u] = num[u] = ++ dfn;
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
        ++ scc_cnt;
        int y;
        do {
            y = stk[-- top];
            id[y] = scc_cnt;
            sz[scc_cnt] ++;
        } while (y != u);
    }
}

int main () {
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    while (m --) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    for (int i = 1; i <= n; i ++) {
        if (!num[i])    
            tarjan(i);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = h[i]; ~j; j = nxt[j]) {
            int v = e[j];
            if (id[i] != id[v]) {
                dout[id[i]] ++;
            }
        }
    }
    int zeros = 0, sum = 0;
    for (int i = 1; i <= scc_cnt; i ++) {
        if (dout[i] == 0) {
            zeros ++;
            sum += sz[i];
        } 
        
        if (zeros > 1) {
            sum = 0;
            break;
        }
    }
    printf("%d\n", sum);
    return 0;
}
```

