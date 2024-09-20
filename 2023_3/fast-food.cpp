// 2023 Fase 3: Fast-Food (https://neps.academy/br/exercise/2573)

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct Quadrado {
    Quadrado(const pair<int, int>& P, const pair<int, int>& Q) {
        int minx = min(P.x, Q.x), miny = min(P.y, Q.y);
        int maxx = max(P.x, Q.x), maxy = max(P.y, Q.y);
        A = { minx, miny }, B = { maxx, maxy };
    }

    bool contains(const pair<int, int>& P) {
        return A.x <= P.x and P.x <= B.x and A.y <= P.y and P.y <= B.y;
    }

    // A.x, A.y < B.x, B.y
    pair<int, int> A, B;
};

signed main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ps;
    ps.resize(n);
    for (auto& [x, y] : ps) cin >> x;
    for (auto& [x, y] : ps) cin >> y;

    // distância chebyshev, bounding box alinhada nos eixos
    int minx = 1e9, miny = 1e9, maxx = -5e8, maxy = -5e8;
    for (auto& [x, y] : ps) {
        int tmp = x;
        x = x + y;
        y = tmp - y;
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }

    // existe uma bounding box que contém ps, chamemos de
    // original. queremos fazer outras duas que o maior
    // lado delas é o menor possível e a união dos pontos
    // contidos nelas é igual à ps. como só o maior lado
    // importa elas podem ser quadrados. podemos fazer
    // uma busca binária pra ir chutando o tamanho. elas
    // devem começar distante uma da outra. como na original
    // há pelo menos um ponto em cada aresta elas devem
    // começar nos vértices das diagonais porque não
    // faz sentido elas começarem em vértices adjascentes
    // se não elas nunca iam ser menores que um dos lados
    // da original

    int ans = 1e9;
    for (int i = 0; i < 2; ++i) {
        pair<int, int> A(minx, miny), D(maxx, maxy);
        if (i == 1) A = { minx, maxy }, D = { maxx, miny };
        int l = 0, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            pair<int, int> B(minx + m, miny + m), C(maxx - m, maxy - m);
            if (i == 1) B = { minx + m, maxy - m }, C = { maxx - m, miny + m };
            Quadrado azuis(A, B), vermelhos(C, D);
            bool ok = true;
            for (auto p : ps)
                if (!azuis.contains(p) and !vermelhos.contains(p))
                    ok = false;
            if (!ok) l = m + 1;
            else r = m;
        }
        ans = min(ans, r);
    }
    cout << ans << '\n';
}
