存在环，则说明除了最短路之外还存在其他边。也就是我们可以用两个数组，一个数组存边，一个数组存最短路，但要保证边不在最短路中。

**思路**: 在最短路中枚举的点编号一定都小于某个编号k，而如果k在环中，k一定和i, j有连边关系，那就考虑把环中最大点的编号作为最短路和边的分界。和floyd顺序一样先枚举k，只是在计算环的时候，i、j的编号都要小于k，并且最短路的更新不是预处理的，而是在线的，也就是每次在计算了环之后再把点k加入最短路中。这种思路还是很值的学习的。（编号最大）

因此在枚举更新环的i, j时，

利用floyd的性质：

1. 若i, j间存在最短路，路径上必没有重复点
2. i, j间最短路存在最后更新i, j的编号最大的点k，返回路径可以用类似树的中序遍历的方式

```c++
​```c++
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 110, M = 10010;
int h[N], e[M], nxt[M], w[M], idx, d[N][N], g[N][N], pos[N][N], cnt = 0, ans[N];
typedef long long LL;
void add(int u, int v, int we) {
    e[idx] = v;
    w[idx] = we;
    nxt[idx] = h[u];
    h[u] = idx ++;
}

void getpath(int i, int j) {
    if (pos[i][j] == 0) return;
    int point = pos[i][j];
    getpath(i, point);
    ans[cnt ++] = point;
    getpath(point, j);
    
}

int main() {
    scanf("%d %d", &n, &m);

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++) g[i][i] = 0;
    while (m --) {
        int u, v, i;
        scanf("%d %d %d", &u, &v, &i);
        g[u][v] = g[v][u] = min(g[u][v], i);
    }
    memcpy(d, g, sizeof g);
    int res = 0x3f3f3f3f;
    //k 是 i, j最短路途中最大编号
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i < k; i ++) {
            for (int j = i + 1; j < k; j ++) {
                if ((LL)d[i][j] + g[i][k] + g[k][j] < res) {
                    res = d[i][j] + g[i][k] + g[k][j];
                    cnt = 0;
                    ans[cnt ++] = k; //编号最大的点需要存储
                    ans[cnt ++] = i;
                    getpath(i, j);
                    ans[cnt ++] = j;
                }
            }
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (d[i][j] > (LL) d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
            }
        }
    }
    if (res == 0x3f3f3f3f) puts("No solution.");
    else {
        
        for (int i = 0; i < cnt; i ++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    
    return 0;
}
​```
```

