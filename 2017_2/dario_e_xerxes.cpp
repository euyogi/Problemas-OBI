// 2017 Fase 2: Dario e Xerxes (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f2/xerxes/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<vector<bool>> g(5, vector<bool>(5));

    g[0][1] = true;
    g[1][2] = true;
    g[2][3] = true;
    g[3][4] = true;
    g[4][0] = true;
    g[0][2] = true;
    g[1][3] = true;
    g[2][4] = true;
    g[3][0] = true;
    g[4][1] = true;

    int dario = 0, xerxes = 0, d, x;

    while (n--) {
        cin >> d >> x;
        if (g[d][x])
            ++dario;
        else
            ++xerxes;
    }

    if (dario > xerxes)
        cout << "dario\n";
    else
        cout << "xerxes\n";
}