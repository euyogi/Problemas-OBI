// 2020 Fase 3: Jogo do Preto e Branco (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f3/jogo/)

#include <bits/stdc++.h>
using namespace std;

enum TIPOS { VAZIO, PRETO, BRANCO };
vector<pair<int, int>> ds { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int l, c;
vector<vector<TIPOS>> m;
vector<pair<int, int>> disponiveis;

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < l and j < c;
}

int backtracking(int i) {
    if (i == disponiveis.size()) return 0;
    auto [x, y] = disponiveis[i];
    int deixa_vazio = backtracking(i + 1);

    for (auto [ox, oy] : ds)
        if (valid(x + ox, y + oy) and m[x + ox][y + oy] == BRANCO)
            return deixa_vazio;

    m[x][y] = BRANCO;
    int coloca_branco = backtracking(i + 1) + 1;
    m[x][y] = VAZIO;

    return max(deixa_vazio, coloca_branco);
}

signed main() {
    int p;
    cin >> l >> c >> p;

    m.resize(l, vector<TIPOS>(c));
    vector<pair<int, int>> ps(p);
    for (auto& [x, y] : ps) {
        cin >> x >> y;
        --x, --y;
        m[x][y] = PRETO;
    }

    set<pair<int, int>> unicos;
    for (auto [x, y] : ps)
        for (auto [ox, oy] : ds)
            if (valid(x + ox, y + oy) and m[x + ox][y + oy] == VAZIO)
                unicos.emplace(x + ox, y + oy);

    for (auto unico : unicos)
        disponiveis.emplace_back(unico);

    cout << backtracking(0) << '\n';
}
