// 2021 Fase 2: Retângulo (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/retangulo/)

#include <bits/stdc++.h>
using namespace std;

#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    int n, perimetro = 0, diagonais = 0;
    cin >> n;

    set<int> ps;
    for (int i = 0, marc; i < n; ++i) {
        cin >> marc;
        perimetro += marc;
        ps.emplace(perimetro);
    }

    for (int i : ps)
        if (found(i + perimetro / 2, ps))
            ++diagonais;

    if (perimetro % 2 == 0 and diagonais >= 2)
        cout << "S\n";
    else
        cout << "N\n";
}
