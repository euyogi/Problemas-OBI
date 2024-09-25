// 2021 Fase 3: Teclado (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f3/teclado/)

#include <bits/stdc++.h>
using namespace std;

// bem hardcoded mas n importa kkkk

signed main() {
    string num;
    int n;
    cin >> num >> n;

    map<char, string> mp {
        {'a', "2"}, {'b', "2"}, {'c', "2"},
        {'d', "3"}, {'e', "3"}, {'f', "3"},
        {'g', "4"}, {'h', "4"}, {'i', "4"},
        {'j', "5"}, {'k', "5"}, {'l', "5"},
        {'n', "6"}, {'m', "6"}, {'o', "6"},
        {'p', "7"}, {'q', "7"}, {'r', "7"}, {'s', "7"},
        {'t', "8"}, {'u', "8"}, {'v', "8"},
        {'w', "9"}, {'x', "9"}, {'y', "9"}, {'z', "9"}
    };

    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        string num_s;
        for (char c : s)
            num_s += mp[c];
        if (num == num_s) ++ans;
    }
    cout << ans << '\n';
}
