kruskal + 二分(其实不用二分，因为从小到大枚举其实就已经有单调性在里面了)

```c++
#include <bits/stdc++.h>

using namespace std;
const int N= 510, M = N * N;
int n, k, idx = 0;
struct E{
    int u, v;
    double d;
    bool operator < (E edge) const{
        return d < edge.d;
    }
}e[M];
int par[N];
int findp(int x) {
    return x == par[x] ? x : findp(par[x]);
}
bool uni(int x, int y) {
    x = findp(x), y = findp(y);
    if (x == y) return false;
    par[y] = x;
    return true;
}
pair<int, int> p[N];
double cal(int i, int j) {
    return sqrt((double)(p[i].first - p[j].first) * (p[i].first - p[j].first) + (double)(p[i].second - p[j].second) * (p[i].second - p[j].second));
}


bool check(int mid) {
    double dis = e[mid].d;
    int iset = -1, cnt = 1;
    for (int i = 0; i < idx; i ++) {
        if (e[i].d <= dis) {
            uni(e[i].u, e[i].v);
            iset = e[i].u;
        } else {
            if (iset != -1) {
                int p1 = findp(iset), p2 = findp(e[i].u), p3 = findp(e[i].v);
                if (p2 == p3) continue;
                if (p1 != p2) {
                    uni(p1, p2);
                    cnt ++;
                }
                if (p1 != p3) {
                    uni(p1, p3);
                    cnt ++;
                }
            }
        }
    }
    // cout << dis << " " << cnt << endl;
    return cnt <= k;
}

void init() {
    for (int i = 0; i < n; i ++) par[i] = i;
}

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        p[i].first = a, p[i].second = b;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            e[idx].u = i, e[idx].v = j;
            e[idx ++].d = cal(i, j);
            // cout << i << " " << j << " " << cal(i, j) << endl;
        }
    }
    sort(e, e + idx);
    if (k == n) {
        printf("%.2lf\n", 0);
        return 0;
    }
    
    int l = 0, r = idx - 1;
    while (l < r) {
        init();
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%.2lf\n", e[l].d);
    return 0;
}
```

