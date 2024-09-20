// 2023 Fase 3: Trio de Bonecas (https://neps.academy/br/exercise/2572)

#include <bits/stdc++.h>
using namespace std;

#define int long long

// [posição, restam]
vector dp(1e4 + 10, vector<int>(3e3 + 10, -1));

int minimum(int i, int r, vector<int>& hs) {
    if (r == 0) return 0;
    // só é possível escolher a dupla (i, i + 1)
    // se conseguimos pegar o terceiro pra todos
    // os trios restantes incluindo este
    if (hs.size() - i < r * 3) return INT_MAX;
    if (dp[i][r] != -1) return dp[i][r];
    return dp[i][r] = min(minimum(i + 1, r, hs), (hs[i] - hs[i + 1]) * (hs[i] - hs[i + 1]) + minimum(i + 2, r - 1, hs));
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> hs(n);
    for (int& h : hs) cin >> h;
    sort(hs.begin(), hs.end());

    cout << minimum(0, k, hs) << '\n';
}
