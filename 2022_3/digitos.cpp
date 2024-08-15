// 2023 Fase 3: Dígitos (https://neps.academy/br/exercise/2168)

#include <bits/stdc++.h>
using namespace std;

void somar1(string& a) {
    bool carrega = true;
    for (int i = a.size() - 1; i >= 0 and carrega; --i) {
        if (a[i] == '9') a[i] = '0';
        else {
            ++a[i];
            carrega = false;
        }
    }
    if (carrega) a.insert(a.begin(), '1');
}

signed main() {
    int n;
    cin >> n;

    string quadro, a = "", b;

    for (int i = 0, j; i < n; ++i) {
        cin >> j;
        quadro += to_string(j);
    }

    for (int i = 0; i < n; ++i) {
        a += quadro[i], b = a;
        string a_to_b = a;

        while (a_to_b.size() < n) {
            somar1(b);
            a_to_b += b;
        }

        if (quadro == a_to_b) {
            cout << a << '\n';
            break;
        }
    }
}
