// 2021 Fase 2: Passatempo (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/passatempo/)

#include <bits/stdc++.h>
using namespace std;

constexpr int DESCONHECIDA = 1e9;

int l, c, conhecidas = 0;

map<string, int> vs;
vector<vector<string>> m;
vector<int> sum_lin, sum_col;

void procurarUnica() {
    for (int i = 0; i < l; ++i) {
        string v;
        bool apenas_v = true;
        int sub = 0, qnt = 0;
        for (int j = 0; j < c; ++j) {
            if (v.empty() and vs[m[i][j]] == DESCONHECIDA)
                v = m[i][j];

            if (!v.empty() and m[i][j] != v and vs[m[i][j]] == DESCONHECIDA)
                apenas_v = false;

            if (v.empty() or m[i][j] != v) {
                sub += vs[m[i][j]];
                ++qnt;
            }
        }

        if (!v.empty() and apenas_v) {
            vs[v] = (sum_lin[i] - sub) / (c - qnt);
            ++conhecidas;
        }
    }

    for (int i = 0; i < c; ++i) {
        string v;
        bool apenas_v = true;
        int sub = 0, qnt = 0;
        for (int j = 0; j < l; ++j) {
            if (v.empty() and vs[m[j][i]] == DESCONHECIDA)
                v = m[j][i];

            if (!v.empty() and m[j][i] != v and vs[m[j][i]] == DESCONHECIDA)
                apenas_v = false;

            if (v.empty() or m[j][i] != v) {
                sub += vs[m[j][i]];
                ++qnt;
            }
        }

        if (!v.empty() and apenas_v) {
            vs[v] = (sum_col[i] - sub) / (l - qnt);
            ++conhecidas;
        }
    }
}

signed main() {
    cin >> l >> c;
    m.resize(l, vector<string>(c));
    sum_lin.resize(l);
    sum_col.resize(c);

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> m[i][j];
            vs[m[i][j]] = DESCONHECIDA;
        }

        cin >> sum_lin[i];
    }

    for (int i = 0; i < c; ++i)
        cin >> sum_col[i];

    while (conhecidas < vs.size())
        procurarUnica();

    for (auto& [var, val] : vs)
        cout << var << ' ' << val << '\n';
}
