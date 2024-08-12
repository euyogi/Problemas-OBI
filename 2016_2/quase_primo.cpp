// 2016 Fase 2: Quase Primo (https://olimpiada.ic.unicamp.br/pratique/p2/2016/f2/quase-primo/)

#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<int> ps;

// dá pra representar os conjuntos por um único número
// pois um número é representado por um único conjunto de primos
// e vice-versa
int f(int sz, int num, int qtd) {
    if (num > n) return 0;
    // princípio inclusão exclusão
    if (sz == ps.size()) {
        int ans = n / num; // qtd divisores de num de 1 até n
        if (qtd > 0 and qtd & 1)
            return ans;
        else if (qtd > 0)
            return -ans;
        return 0;
    }
    return f(sz + 1, num * ps[sz], qtd + 1) + f(sz + 1, num, qtd);
}

signed main() {
    int k;
    cin >> n >> k;
    ps.resize(k);
    for (int& p : ps) cin >> p;
    cout << n - f(0, 1, 0) << '\n';
}
