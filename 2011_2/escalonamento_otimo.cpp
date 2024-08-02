// 2011 Fase 2: Escalonamento Ótimo (https://neps.academy/br/exercise/331)

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& g) {
    vector<int> degree(g.size()), res;
    for (int i = 0; i < g.size(); ++i)
        for (auto u : g[i])
            ++degree[u];

    // valores menores maiores prioridades
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < degree.size(); ++i)
        if (degree[i] == 0) pq.emplace(i);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        res.emplace_back(u);
        for (int v : g[u])
            if (--degree[v] == 0)
                pq.emplace(v);
    }

    if (res.size() != g.size())
        return {}; // ciclo

    return res;
}

signed main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> g(n);
    while (m--) {
        cin >> a >> b;
        g[a].emplace_back(b);
    }

    auto v = topologicalSort(g);

    if (v.empty())
        cout << "*\n";
    else
        for (int u : v)
            cout << u << '\n';
}
