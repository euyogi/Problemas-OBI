// 2022 Fase 2: Tanque de combustível (https://neps.academy/br/exercise/2129)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int c, d, t;
    cin >> c >> d >> t;

    int resta = max(0, d - (t * c));
    printf("%.1Lf\n", 1.0L * resta / c);
}
