// 2016 Fase 2: Arco e Flecha (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/arco-online/) (60-80/100)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> RBT;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, x, y, penalidade_anterior = 0, dist;
    RBT rbt;

    cin >> n;

    while (n--) {
        cin >> x >> y;

        x += penalidade_anterior;
        y += penalidade_anterior;

        dist = x * x + y * y;

        // + 1 because we need to count equal distance arrows
        penalidade_anterior = rbt.order_of_key(dist + 1);
        rbt.insert(dist);
        cout << penalidade_anterior << '\n';
    }
}
