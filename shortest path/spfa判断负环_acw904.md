- [ spfa](#head1)
- [bellman ford](#head2)

1. 判断负环: spfa元素更新n次（n次入队），这说明松弛了n次，而n个点无环最多松弛n - 1次，说明必然存在环。

   

   需要注意的是，1. dist无需初始化，且一开始所有元素入队。2. cnt[v] = cnt[u] + 1 (不是cnt[v] ++) 。3. 用数组模拟双端队列会快些

2. bellman ford, 如果松弛n次必然存在环（原理和spfa一样）

## <span id="head1"> spfa</span>

```c++
​```c++
#include <bits/stdc++.h>

using namespace std;

int n, m, ww, idx = 0;

const int N = 510, M = 2510 * 2 + 300;
int e[M], w[M], h[N], nxt[M];
void add (int u, int v, int we) {
    e[idx] = v;
    w[idx] = we;
    nxt[idx] = h[u];
    h[u] = idx ++;
}
bool spfa() {
    int dist[N], cnt[N];
    bool vis[N];
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    int q[N];
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i ++) {
        q[tt ++] = i;
        vis[i] = true;
    }
    
    while (hh ^ tt) {
        int u = q[hh ++];
        if (hh == N) hh = 0;
        if (cnt[u] == n) return true;
        vis[u] = false;
        for (int i = h[u]; ~i; i = nxt[i]) {
            int j = e[i];
            if (dist[j] > dist[u] + w[i]) {
                dist[j] = dist[u] + w[i];
                cnt[j] = cnt[u] + 1;
                if (!vis[j]) {
                    q[tt ++] = j;
                    vis[j] = true;
                    if (tt == N) tt = 0;
                    
                }
            }
        }
    }
    return false;
}
int main() {
    int f;
    scanf("%d", &f);
    while (f --) {
        memset(h, -1, sizeof h);
        idx = 0;
        scanf("%d %d %d", &n, &m, &ww);
        while (m --) {
            int s, e, t;
            scanf("%d %d %d", &s ,&e, &t);
            add(s, e, t);
            add(e, s, t);
        }
        while (ww --) {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            add(s, e, - t);
        }
        if (spfa()) puts("YES");
        else puts("NO");
        
    }
    return 0;
}
```
## <span id="head2">bellman ford</span>

```c++
​```c++
#include<bits/stdc++.h>
using namespace std;
const int N = 10010, inf = 0x3f3f3f3f;
int n, m;
struct Edge{
    int u,v,w;
}edge[N];
bool bellman() {
        int dist[N];
        for(int j=1;j<=n;j++){
            bool update = false;
            for(int k = 0;k<m;k++){
                if(dist[edge[k].u]>dist[edge[k].v]+edge[k].w){
                    dist[edge[k].u] = dist[edge[k].v]+edge[k].w;
                    update = true;
                }
            }
            if(j==n && update)
                return true;
        }

    return false;

}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,wei;
        scanf("%d%d%d",&u,&v,&wei);
        edge[i] = {u,v,wei};
    }
    if(bellman()) puts("Yes");
    else puts("No");
    return 0;
}
```