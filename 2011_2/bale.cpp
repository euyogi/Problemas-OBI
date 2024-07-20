// 2011 Fase 2: Balé (https://neps.academy/br/exercise/536)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> RBT;

#define all(xs) xs.begin(), xs.end()

signed main() {
    int n, ans = 0;
    cin >> n;

    vector<int> xs(n);
    for (int& x : xs) cin >> x;
    reverse(all(xs));

    RBT rbt;
    for (int x : xs) {
        ans += rbt.order_of_key(x);
        rbt.insert(x);
    }

    cout << ans << '\n';
}
