// 2023 Fase 3: Caravanas (https://neps.academy/br/exercise/2171)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int& x : xs) cin >> x;
    int media = accumulate(xs.begin(), xs.end(), 0) / n;
    for (int x : xs) cout << media - x << '\n';
}
