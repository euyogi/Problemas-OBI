// 2022 Fase 3: Dona Minhoca (https://neps.academy/br/exercise/2172)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int raio;

// vai das folhas pra raiz vendo se é necessário
// por um radar aqui (distância do meu filho mais
// distante é igual ao raio, obviamente não vai ser
// alcançado por outro radar), se sim põe, "apaga os
// filhos e eu" e sobe. guarda a distância do último
// radar para saber se eu to dentro do raio, se sim
// me deleta, no caso da raíz mesmo se ela estiver
// dentro do radar checa primeiro se tem algum filho fora

// (qtd radares, dist do último radar, altura)
tuple<int, int, int> dfs(int u, int p) {
    int q = 0, d = 4e5, h = 0;
    for (int v : g[u]) if (v != p) {
        auto [q_, d_, h_] = dfs(v, u);
        q += q_;
        d = min(d, d_);
        h = max(h, h_);
    }
    // não deu exatamente igual ao raio, mas
    // como é o último nó temos que por um radar
    if (u == 1 and d + h > raio)
        ++q;
    else if (h == raio) // se não pormos agora fica fora
        ++q, d = 0;
    if (d + h <= raio) // dentro: exclui nó
        h = -1;
    return { q, d + 1, h + 1 };
}

signed main() {
    int n, k;
    cin >> n >> k;
    g.resize(n + 1);

    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int l = 0, r = n, m;
    while (l < r) {
        m = raio = (l + r) / 2;
        auto [q, _, __] = dfs(1, 0);
        if (q > k) l = m + 1;
        else r = m;
    }
    cout << r << '\n';
}
