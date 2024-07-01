// 2016 Fase 2: Jardim de infância (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/jardim/)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define x first
#define y second

void sub(pll& a, pll& b) {
    a.x -= b.x;
    a.y -= b.y;
}

ll comprimento(const pll& a, const pll& b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }

ll produto_interno(const pll& a, const pll& b) { return a.x * b.x + a.y * b.y; }

// <a, b> = ||a||.||b||.cos(x)
// se <a, b> == 0, perpendicular
// se <a, b> > 0, agudo
// se <a, b> < 0, obtuso
// se |<a, b>| == ||a||.||b||, colinearidade

bool colinear(pll a, pll b, pll c) {
    sub(b, a);
    sub(c, a);

    if (produto_interno(b, c) * produto_interno(b, c) == comprimento(b, { 0, 0 }) * comprimento(c, { 0, 0 }))
        return true;
    return false;
}

bool agudo(pll a, pll b, pll c) {
    sub(b, a);
    sub(c, a);

    if (produto_interno(b, c) > 0)
        return true;
    return false;
}

bool perpendicular(pll a, pll b, pll c, pll d) {
    sub(b, a);
    sub(d, c);

    if (produto_interno(b, d) == 0)
        return true;
    return false;
}

// D = 0: p pertence à reta
// D > 0: p à esquerda
// D < 0: p à direita
ll D(const pll& a, const pll& b, const pll& p) {
    return (a.x * b.y + a.y * p.x + b.x * p.y) - (p.x * b.y + p.y * a.x + b.x * a.y);
}

char isPinheiro(vpll& p) {
    if (!agudo(p[1], p[2], p[3])) // 1
        return 'N';
    if (comprimento(p[1], p[2]) != comprimento(p[1], p[3])) // 2
        return 'N';
    if (!colinear(p[2], p[3], p[4]) || !colinear(p[3], p[4], p[5])) // 3
        return 'N';
    if (comprimento(p[2], p[4]) != comprimento(p[5], p[3])) // 4
        return 'N';
    if (comprimento(p[2], p[3]) <= comprimento(p[4], p[5])) // 5
        return 'N';
    if (!perpendicular(p[4], p[6], p[2], p[3]) || !perpendicular(p[5], p[7], p[2], p[3])) // 6
        return 'N';
    if (comprimento(p[4], p[6]) != comprimento(p[5], p[7])) // 7
        return 'N';
    if (!((D(p[2],p[3], p[1]) < 0 and D(p[2],p[3], p[6]) > 0) or (D(p[2],p[3], p[1]) > 0 and D(p[2],p[3], p[6]) < 0)))
        return 'N';
    return 'S';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vpll p(8);
    for (ll i = 1; i <= 7; ++i)
        cin >> p[i].first >> p[i].second;

    cout << isPinheiro(p) << '\n';
}
