// 2018 Fase 2: Fuga (https://olimpiada.ic.unicamp.br/pratique/ps/2018/f2/fuga/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m, xe, ye, xs, ys;
    cin >> n >> m >> xe >> ye >> xs >> ys;

    vector<vector<bool>> g(n + 1, vector<bool>(m + 1));
    for (int i = 2; i < n; i += 2)
        for (int j = 2; j < m; j += 2)
            g[i][j] = true;

    vector<pair<int, int>> ds { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    // independentemente do caminho é possível derrubar
    // os armários de forma que este se torne o menor
    auto dfs = [&](auto&& self, int x, int y) -> int {
        if (x == xs and y == ys) return 1;
        g[x][y] = true;
        int ans = 0;
        for (auto [ox, oy] : ds) {
            int nx = x + ox, ny = y + oy;
            if (nx < 1 or ny < 1 or nx > n or ny > m) continue;
            if (g[nx][ny]) continue;
            ans = max(ans, self(self, nx, ny) + 1);
        }
        g[x][y] = false;
        return ans;
    };

    cout << dfs(dfs, xe, ye) << '\n';
}
