// 2024 Fase 2: Jogo do Poder (https://neps.academy/br/exercise/2798)

#include <bits/stdc++.h>
using namespace std;

int h, w;
#define I(i, j) ((i) * w + j)

struct DSU {
    DSU(int n, vector<long long>& g)
        : parent(n + 1), size(n + 1, 1), value(n + 1), inside(n + 1), around(n + 1) {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                parent[I(i, j)] = I(i, j);
                value[I(i, j)] = g[I(i, j)];
                inside[I(i, j)].emplace(I(i, j));
                if (i > 0)     around[I(i, j)].emplace(I(i - 1, j));
                if (j > 0)     around[I(i, j)].emplace(I(i, j - 1));
                if (i + 1 < h) around[I(i, j)].emplace(I(i + 1, j));
                if (j + 1 < w) around[I(i, j)].emplace(I(i, j + 1));
            }
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void merge(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) return;
        if (size[a] > size[b]) swap(a, b);
        parent[a] = b;
        size[b] += size[a];
        value[b] += value[a];
        inside[b].insert(inside[a].begin(), inside[a].end());
        around[b].insert(around[a].begin(), around[a].end());
    }

    vector<int> parent, size;
    vector<long long> value;
    vector<unordered_set<int>> inside, around;
};

signed main() {
    cin >> h >> w;

    vector<long long> g(h * w), ans = g;
    // guarda o índice do grupo e a gente faz as operações do menor
    // pro maior, se um grupo ficou maior a gente insere na fila
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            cin >> g[I(i, j)];
            pq.emplace(g[I(i, j)], I(i, j));
        }

    DSU d(h * w, g);

    while (!pq.empty()) {
        auto [value, x] = pq.top();
        pq.pop();
        int a = d.find(x);
        // o valor desse grupo já ficou maior
        if (value < d.value[a]) continue;

        stack<int> merge_stack;
        auto it = d.around[a].begin();
        while (it != d.around[a].end()) {
            // ainda não derrotamos e conseguimos derrotar
            if (value >= g[*it] and d.find(*it) != a)
                merge_stack.emplace(*it);
            if (d.find(*it) == a) it = d.around[a].erase(it);
            else ++it;
        }

        // não tem mais ninguém em volta que conseguimos derrotar
        if (merge_stack.empty()) {
            for (int idx : d.inside[a])
                ans[idx] = value; // a resposta pra esse pessoal é a mesma
            d.inside[a].clear();
            continue;
        }

        // junta o pessoal que conseguimos derrotar
        while (!merge_stack.empty()) {
            int y = merge_stack.top();
            merge_stack.pop();
            d.merge(x, y);
        }
        a = d.find(x);
        pq.emplace(d.value[a], x);
    }

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cout << ans[I(i, j)] << (j == w - 1 ? '\n' : ' ');
}
