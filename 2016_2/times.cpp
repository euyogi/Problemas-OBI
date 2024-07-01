// 2016 Fase 2: Times (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/times/)
// TODO: TESTAR SOLUÇÃO!!!

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    set<int> time_do_1, outro_time;

    for (int i = 1, m; i <= n; ++i) {
        cin >> m;
        bool entra_no_1 = true;

        for (int j = 0, x; j < m; ++j) {
            cin >> x;

            if (found(x, time_do_1))
                entra_no_1 = false;
        }

        if (entra_no_1)
            time_do_1.emplace(i);
        else
            outro_time.emplace(i);
    }

    vector<int> xs(all(time_do_1));
    vector<int> ys(all(outro_time));

    for (int i = 0; i < xs.size(); ++i)
        cout << xs[i] << (i == xs.size() - 1 ? '\n' : ' ');
    for (int i = 0; i < ys.size(); ++i)
        cout << ys[i] << (i == ys.size() - 1 ? '\n' : ' ');
}
