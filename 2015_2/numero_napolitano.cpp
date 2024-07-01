// 2015 Fase 2

#include <bits/stdc++.h>
using namespace std;

map<char, int> VALUE_OF {
    { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 },
    { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
};

signed main() {
    string s;
    cin >> s;

    vector<int> values(s.size());
    for (int i = 0; i < s.size(); ++i)
        values[i] = VALUE_OF[s[i]];

    unordered_map<char, int> lasts; // Última posição de cada letra
    vector<int> nexts(s.size(), s.size()); // Posição do próximo maior

    for (int i = s.size() - 1; i >= 0; --i) {
        // P/ cada letra maior que eu o próximo vai ser o menor
        // entre o próximo atual e a última posição dessa letra
        for (auto [c, j] : lasts)
            if (values[i] < VALUE_OF[c])
                nexts[i] = min(nexts[i], j);

        lasts[s[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (nexts[i] != s.size()) // Tem letra maior que eu
            values[nexts[i]] -= values[i];
        else
            ans += values[i];
    }

    cout << ans << '\n';
}
