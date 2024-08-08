// 2022 Fase 2: Subcadeias (https://neps.academy/br/exercise/2131)

#include <bits/stdc++.h>
using namespace std;

bool palindrome(string& s, int l, int r) {
    if (l >= r) return true;
    return s[l] == s[r] and palindrome(s, l + 1, r - 1);
}

signed main() {
    int n;
    string s;
    cin >> n >> s;

    int maior = 1;
    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r)
            if (palindrome(s, l, r))
                maior = max(maior, r - l + 1);

    cout << maior << '\n';
}
