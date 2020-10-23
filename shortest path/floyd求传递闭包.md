折腾了一晚上。。

注意判断的**优先级**：inconsistent 在 其他所有优先级之前

此外本题的一个漏洞是在输出最优解之后其实可能会出现inconsistent，不过没有卡这个的样例

传递性最核心的其实就是通过floyd的公式传递确定的不等关系

```c++
#include <bits/stdc++.h>

using namespace std;
const int N = 26;
int n, m;
int d[N][N], g[N][N];
bool st[N];
void print() {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void floyd() {
    // memcpy(d, g, sizeof d);
    for (int k = 0; k < n; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                d[i][j] |= d[i][k] && d[k][j];
            }
        }
    }
}

int getType() {
    bool dt = true;
    //如果有inconsistence, 其优先级更高
    for (int i = 0; i < n; i ++) 
        if (d[i][i]) {
            return 2;
        }
        
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (!d[i][j] && !d[j][i]) return 0;
        }
    }
    // if (!dt) return 0;
    return 1;
    
}

char getmin() {
    for (int i = 0; i < n; i ++) {
        bool update = false;
        if (!st[i]) {
            for (int j = 0; j < n; j ++) {
                if (!st[j] && d[j][i]) {
                    update = true;
                    break;
                }
            }
            if (!update)  {
                st[i] = true;
                return 'A' + i;
            }
        }

    }
    // return ' ';
}
int t, idx;
int main () {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        
        memset(d, 0, sizeof d);
        memset(st, 0, sizeof st);
        t = 0, idx = 1;
        int te;
        while(m --) {
            char str[5];

            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';

            if (t == 0) {
                d[a][b] = 1;
                floyd();
                t = getType();
                if (t) te = idx;
            }

               
            idx ++;
        }

        if (!t)
            printf("Sorted sequence cannot be determined.\n");
        else if (t == 2) {
            printf("Inconsistency found after %d relations.\n", te);
        }
        else {
            printf("Sorted sequence determined after %d relations: ", te);
            for (int i = 0; i < n; i ++)
                printf("%c", getmin());
            puts(".");
        }
        
        
    }
    return 0;
}
```

