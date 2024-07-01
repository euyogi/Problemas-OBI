// 2014 Fase 2: Voo (https://olimpiada.ic.unicamp.br/pratique/ps/2014/f2/voo/)

#include <bits/stdc++.h>
using namespace std;

constexpr int DAY = 24 * 60;

signed main() {
    int p_Ah, c_Bh, p_Bh, c_Ah;
    int p_Am, c_Bm, p_Bm, c_Am;
    char ig;
    cin >> p_Ah >> ig >> p_Am >> c_Bh >> ig >> c_Bm;
    cin >> p_Bh >> ig >> p_Bm >> c_Ah >> ig >> c_Am;
    // 10:00 22:00 10:00 18:00

    // Convertendo para minutos
    int p_A = 60 * p_Ah + p_Am;
    int c_B = 60 * c_Bh + c_Bm;
    int p_B = 60 * p_Bh + p_Bm;
    int c_A = 60 * c_Ah + c_Am;

    for (int i = -11; i <= 12; ++i) {
        int d1 = c_B - i * 60 - p_A;
        int d2 = c_A + i * 60 - p_B;

        if (d1 < 0) d1 += DAY;
        if (d2 < 0) d2 += DAY;

        if (d1 > DAY) d1 -= DAY;
        if (d2 > DAY) d2 -= DAY;

        if (d1 == d2 and d1 < DAY / 2)
            cout << d1 << ' ' << i << '\n';
    }
}
