层次遍历，注意vis要在队列push进去之后就立马置1，否则可能会使cnt重复被减

```c++
class Solution {
public:
    typedef pair<int, int> pii;
    #define ar array 
    int orangesRotting(vector<vector<int>>& grid) {
        const int dx[] = {0, 0 , 1, -1}, dy[] = {1, -1, 0, 0};
        int n = grid.size(), m = grid[0].size();
        queue<ar<int, 2>> q;
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    cnt ++;
                }
            }
        }
        vector<vector<bool>> vis(n, vector<bool>(m));
        int step = 0;
        while (q.size()) {
            int sz = q.size();
            // cout << sz << " " << cnt << endl;
            if (!cnt) break;
            while (sz --) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i ++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny]) continue;
                    if (grid[nx][ny] == 1) q.push({nx, ny}), vis[nx][ny] = 1, cnt --;
                }
            }
            step ++;
        }
        return cnt == 0 ? step : -1;
    }
};
```

