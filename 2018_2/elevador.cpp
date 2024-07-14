// 2018 Fase 2: Elevador (https://olimpiada.ic.unicamp.br/pratique/ps/2018/f2/elevador/)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main() {
    int n;
    cin >> n;

    vector<int> xs(n);

    for (int& x : xs) cin >> x;

    sort(all(xs));

    int ant = 0;
    for (int i = 0; i < xs.size(); ++i) {
        if (abs(ant - xs[i]) > 8) {
            cout << "N\n";
            return 0;
        }
        ant = xs[i];
    }

    cout << "S\n";
}
