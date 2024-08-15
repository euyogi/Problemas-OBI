// 2023 Fase 3: Pirâmide (https://neps.academy/br/exercise/2570)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    vector<int> xs(6);
    for (int& x : xs) cin >> x;
    sort(xs.begin(), xs.end());
    do {
        if ((xs[0] == xs[1] + xs[2]) and (xs[0] == xs[3] + xs[4] + xs[5])) {
            cout << "S\n";
            return 0;
        }
    } while (next_permutation(xs.begin(), xs.end()));
    cout << "N\n";
}
