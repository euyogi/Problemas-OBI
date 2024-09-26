// 2020 Fase 3: Torre de Dados (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f3/torre/)

#include <bits/stdc++.h>
using namespace std;

struct Dado {
    // eu acima do dado com base = base
    int getBase(int base) {
        return oposto[base];
    }

    int maiorLado(int base) {
        int op = oposto[base];
        int maior = max(base, op);
        int menor = min(base, op);
        return maior == 6 ? (menor == 5 ? 4 : 5) : 6;
    }

    friend istream& operator>>(istream& is, Dado& d) {
        for (int& l : d.ls)
            is >> l;
        d.updOpostos();
        return is;
    }

    array<int, 6> ls;
    array<int, 7> oposto;

    void updOpostos() {
        oposto[ls[0]] = ls[5];
        oposto[ls[5]] = ls[0];
        oposto[ls[1]] = ls[3];
        oposto[ls[3]] = ls[1];
        oposto[ls[2]] = ls[4];
        oposto[ls[4]] = ls[2];
    }
};

signed main() {
    int n;
    cin >> n;

    vector<Dado> dados(n);
    for (Dado& d : dados) cin >> d;

    // escolher a base do primeiro as bases de todos os outros
    // aí basta escolher o maior lado de cada um sem ser as bases

    int maior_soma = 0;
    for (int i = 1; i <= 6; ++i) {
        int base_i = i;
        int soma_lados = dados[0].maiorLado(base_i);
        for (int j = 1; j < n; ++j) {
            base_i = dados[j].getBase(base_i);
            soma_lados += dados[j].maiorLado(base_i);
        }
        maior_soma = max(maior_soma, soma_lados);
    }

    cout << maior_soma << '\n';
}
