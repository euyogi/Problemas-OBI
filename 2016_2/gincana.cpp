// 2016 Fase 2: Gincana (https://neps.academy/br/exercise/3)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n, m;
    cin >> n >> m;

    // máxima diferença entre dois primos consecutivos <= 10^18
    // é 1476 (https://en.wikipedia.org/wiki/Prime_gap)
    for (; m >= 0; --m)
        if (gcd(n, m) == 1)
            break;

    cout << m << '\n';
}
