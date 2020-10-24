- [ 硬bfs](#head1)
- [ 硬两数和](#head2)
## <span id="head1"> 硬bfs</span>

受到上一题的影响，一开始我竟然用出了这种做法....万物皆可bfs?

复杂度O(n^4), n = 500, 人没了...

```c++
class Solution {
public:
    #define ar array
    typedef pair<int, int> pii;
    #define all(n) begin(n), end(n)
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        sort(all(a));
        sort(all(b));
        sort(all(c));
        sort(all(d));
        queue<ar<int, 5>>q;
        int sz = a.size();
        vector<int> cnta(sz), cntb(sz), cntc(sz), cntd(sz);
        for (int i = 0; i < sz; i ++) {
            int j = i;
            while (j ^ sz && a[j] == a[i])
                cnta[i] ++, j ++;
            i = j - 1;
        }
        for (int i = 0; i < sz; i ++) {
            int j = i;
            while (j ^ sz && b[j] == b[i])
                cntb[i] ++, j ++;
            i = j - 1;
        }
        for (int i = 0; i < sz; i ++) {
            int j = i;
            while (j ^ sz && c[j] == c[i])
                cntc[i] ++, j ++;
            i = j - 1;
        }
        for (int i = 0; i < sz; i ++) {
            int j = i;
            while (j ^ sz && d[j] == d[i])
                cntd[i] ++, j ++;
            i = j - 1;
        }
        // set<int>sa(all(a)), sb(all(b)), sc(all(c)), sd(all(d));
        if (!sz) return 0;
        q.push({0, 0, 0, 0, a[0] + b[0] + c[0] + d[0]});
        map<ar<int, 4>, bool> umap;
        int ans = 0;
        // 500 * 500 * 500 --> 1.25 * 10^7
        while (q.size()) {
            auto [o, p, u, r, s] = q.front();
            q.pop();
            if (umap.count({o, p, u, r})) continue;
            umap[{o, p, u, r}] = true;

            if (s > 0 || max({o, p, u, r}) >= sz) continue;
            else if (s == 0) {
                if (o + cnta[o] < sz && p + cntb[p] ^ sz && u + cntc[u] ^ sz && r + cntd[r] ^ sz)
                    q.push({o + cnta[o], p + cntb[p], u + cntc[u], r + cntd[r], s - a[o] + a[o + cnta[o]] - b[p] + b[p + cntb[p]] \
                     - c[u] + c[u + cntc[u]] - d[r] + d[r + cntd[u]]});
                ans = (ans + cnta[o] * cntb[p] * cntc[u] * cntd[r]);
            } else {
                if (o + cnta[o] < sz)
                    q.push({o + cnta[o], p, u, r, s - a[o] + a[o + cnta[o]]});
                if (p + cntb[p] ^ sz)
                    q.push({o, p + cntb[p], u, r, s - b[p] + b[p + cntb[p]]});
                if (u + cntc[u] ^ sz)
                    q.push({o, p, u +  cntc[u], r, s - c[u] + c[u + cntc[u]]});
                if (r + cntd[r] ^ sz)                
                    q.push({o, p, u, r + cntd[r], s - d[r] + d[r + cntd[r]]});
            }
        } 
        return ans;
    }
};
```

## <span id="head2"> 硬两数和</span>

```c++
class Solution {
public:
    #define ar array
    typedef pair<int, int> pii;
    #define all(n) begin(n), end(n)
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int ans = 0;	
        int n = a.size();
        map<int, int> mp1, mp2;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                mp1[a[i] + b[j]] += 1;
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                mp2[c[i] + d[j]] += 1;
            }
        }
        
        for (auto it : mp1) {
            ans += mp2[0 - it.first] * it.second;
        }
        return ans;
    }
};
```