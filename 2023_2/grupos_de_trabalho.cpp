// 2023 Fase 2: Grupos de Trabalho (https://neps.academy/br/exercise/2436)
// Solução melhor: https://olimpiada.ic.unicamp.br/static/extras/obi2023/solucoes/2023f2ps_grupos/andre.cpp

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int e, m, d, u, v;
    cin >> e >> m >> d;

    set<pair<int, int>> juntos, separados;

    while (m--) {
        cin >> u >> v;
        if (v > u) swap(u, v);
        juntos.emplace(u, v);
    }

    while (d--) {
        cin >> u >> v;
        if (v > u) swap(u, v);
        separados.emplace(u, v);
    }

    int t_separados = separados.size();

    for (int i = 0; i < e / 3; ++i) {
        vector<int> grupo(3);
        for (int& x : grupo) cin >> x;
        sort(grupo.begin(), grupo.end(), greater<>());

        auto it1 = juntos.find({grupo[0], grupo[1]});
        auto it2 = juntos.find({grupo[0], grupo[2]});
        auto it3 = juntos.find({grupo[1], grupo[2]});

        auto it4 = separados.find({grupo[0], grupo[1]});
        auto it5 = separados.find({grupo[0], grupo[2]});
        auto it6 = separados.find({grupo[1], grupo[2]});

        if (it1 != juntos.end())
            juntos.erase(it1);
        if (it2 != juntos.end())
            juntos.erase(it2);
        if (it3 != juntos.end())
            juntos.erase(it3);

        if (it4 != separados.end())
            separados.erase(it4);
        if (it5 != separados.end())
            separados.erase(it5);
        if (it6 != separados.end())
            separados.erase(it6);
    }

    cout << juntos.size() + t_separados - separados.size() << '\n';
}
