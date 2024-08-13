// 2023 Fase 2: Startup (https://neps.academy/br/exercise/2625)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, a, insatisfeitos = 0;
    cin >> n;

    vector<int> pai(n + 1);
    vector<multiset<int, greater<>>> salario_filhos(n + 1);
    vector<int> salario(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> pai[i];
        cin >> salario[i];
        salario_filhos[pai[i]].emplace(salario[i]);
    }

    auto insatisfeito = [&](int i) -> bool {
        int maior_meus_filhos = *salario_filhos[i].begin();
        return salario[i] < maior_meus_filhos;
    };

    for (int i = 1; i <= n; ++i)
        if (insatisfeito(i))
            ++insatisfeitos;
    cout << insatisfeitos << '\n';

    cin >> a;

    while (a--) {
        int i, x;
        cin >> i >> x;

        bool pai_insatisfeito = insatisfeito(pai[i]);
        bool eu_insatisfeito = insatisfeito(i);

        salario_filhos[pai[i]].erase(salario_filhos[pai[i]].find(salario[i]));
        salario_filhos[pai[i]].emplace(x);
        salario[i] = x;

        if (i != 1 and insatisfeito(pai[i])) {
            if (!pai_insatisfeito)
                ++insatisfeitos;
        }
        else if (i != 1) {
            if (pai_insatisfeito)
                --insatisfeitos;
        }

        if (insatisfeito(i)) {
            if (!eu_insatisfeito)
                ++insatisfeitos;
        }
        else {
            if (eu_insatisfeito)
                --insatisfeitos;
        }

        cout << insatisfeitos << '\n';
    }
}
