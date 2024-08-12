// 2015 Fase 2: Macacos me Mordam! (https://olimpiada.ic.unicamp.br/pratique/p2/2015/f2/macacos/)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define all(xs) xs.begin(), xs.end()

template<typename T>
T D(const pair<T, T>& A, const pair<T, T>& B, const pair<T, T>& P) {
    return (A.x * B.y + A.y * P.x + B.x * P.y) -
           (P.x * B.y + P.y * A.x + B.x * A.y);
}

template <typename T>
vector<pair<T, T>> makeHull(vector<pair<T, T>>& ps) {
    vector<pair<T, T>> hull;
    for (auto& p : ps) {
        auto sz = hull.size();
        while (sz >= 2 and D(hull[sz - 2], hull[sz - 1], p) <= 0) {
            hull.pop_back();
            sz = hull.size();
        }
        hull.emplace_back(p);
    }
    return hull;
}

template<typename T>
vector<pair<T, T>> monotoneChain(vector<pair<T, T>> ps) {
    vector<pair<T, T>> lower, upper;
    sort(all(ps));
    lower = makeHull(ps);
    reverse(all(ps));
    upper = makeHull(ps);
    lower.pop_back();
    lower.insert(lower.end(), all(upper));
    return upper; // retornando a parte de cima
}

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arvores(n);
    for (auto& [p, h] : arvores)
        cin >> p >> h;
    cout << monotoneChain(arvores).size() - 1 << '\n';
}
