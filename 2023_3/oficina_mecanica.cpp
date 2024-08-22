// 2023 Fase 3: Oficina Mecânica (https://neps.academy/br/exercise/2568)

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m, ans = 0;
    cin >> n >> m;

    vector<int> ts(n);
    for (int& t : ts) cin >> t;

    sort(ts.begin(), ts.end(), greater<>());

    // quando coloco um carro quero por no mecânico que
    // vai aumentar o mínimo possível, se eu por em um
    // que tem só um carro, vai ser tempo*fator, mas se
    // tem mais carros isso vai aumentar os outros no
    // valor desse, ou seja o total aumentado vai ser
    // t*f*q então eu quero por no mecânico que têm o
    // menor fator*quantidade

    // (fator*quantidade, fator)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    while (m--) {
        int f;
        cin >> f;
        pq.emplace(0, f);
    }

    for (int t : ts) {
        auto [fq, f] = pq.top();
        pq.pop();
        ans += t*fq;
        pq.emplace(fq + f, f);
    }

    cout << ans << '\n';
}
