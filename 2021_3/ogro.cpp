// 2021 Fase 3: Ogro (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f3/ogro/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;

    int direita = min(5, n);
    int esquerda = n - direita;

    if (direita == 0)
        cout << "*\n";
    else {
        for (int i = 0; i < direita; ++i)
            cout << 'I';
        cout << '\n';
    }

    if (esquerda == 0)
        cout << "*\n";
    else {
        for (int i = 0; i < esquerda; ++i)
            cout << 'I';
        cout << '\n';
    }
}
