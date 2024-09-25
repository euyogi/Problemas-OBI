// 2021 Fase 3: Falha de segurança (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f3/falha/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, ans = 0;
    cin >> n;

    unordered_map<string, int> senhas;

    while (n--) {
        string senha;
        cin >> senha;
        ++senhas[senha];
    }

    for (const auto& [senha, qtd] : senhas) {
        unordered_set<string> subs;
        for (int i = 0; i < senha.size(); ++i)
            for (int len = 1; len <= senha.size() - i; ++len) {
                string sub = senha.substr(i, len);
                subs.emplace(sub);
            }

        for (const string& sub : subs)
            if (senhas.find(sub) != senhas.end())
                ans += senhas[sub] * qtd;
        ans -= qtd;
    }

    cout << ans << '\n';
}
