// 2021 Fase 3: Dona Minhoca (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f3/minhoca/)

#include <bits/stdc++.h>
using namespace std;

// para encontrar o comprimento do maior ciclo basta encontrar o diâmetro
// da árvore. contar quantos ciclos tem esse comprimento, vamos utilizar o
// centro, porque o centro faz parte de todos os diâmetros, além disso
// as pontas do diâmetro só podem ser folhas, então para todas as folhas
// vamos ver a distância pro diâmetro e se tiver distâncias que somadas
// dão o diâmetro contamos para os ciclos

signed main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> pai(n + 1);

    auto maisDistante = [&](auto&& self, int u, int p) -> pair<int, int> {
        pai[u] = p;
        pair<int, int> res(0, u);
        for (int v : g[u]) if (v != p)
            res = max(res, self(self, v, u));
        return { res.first + 1, res.second};
    };

    auto [_, nd1] = maisDistante(maisDistante, 1, 0);
    auto [diam, nd2] = maisDistante(maisDistante, nd1, 0);
    --diam;

    int dist_centro = diam / 2;
    int centro = nd2;
    for (int i = 0; i < dist_centro; ++i)
        centro = pai[centro];

    // distâncias para o centro
    vector<int> dist(n + 1);
    dist[0] = -1;

    // eu preciso subtrair as frequências dos que não tem o centro como LCA comigo
    vector<int> ultimo_ancestral(n + 1);
    iota(ultimo_ancestral.begin(), ultimo_ancestral.end(), 0);

    auto calcDists = [&](auto&& self, int u, int p) -> void {
        dist[u] = dist[p] + 1;
        if (u != centro and pai[u] != centro)
            ultimo_ancestral[u] = ultimo_ancestral[p];
        for (int v : g[u]) if (v != p)
            self(self, v, u);
    };

    calcDists(calcDists, centro, 0);

    map<int, int> freq_total;
    map<pair<int, int>, int> freq_na_sub;
    for (int i = 1; i <= n; ++i)
        if (g[i].size() == 1) {
            ++freq_total[dist[i]];
            ++freq_na_sub[{ ultimo_ancestral[i], dist[i] }];
        }

    int qnt = 0;
    for (int i = 1; i <= n; ++i)
        if (g[i].size() == 1)
            qnt += freq_total[diam - dist[i]] - freq_na_sub[{ ultimo_ancestral[i], diam - dist[i] }];

    cout << diam + 1 << '\n';
    cout << qnt / 2 << '\n';
}
