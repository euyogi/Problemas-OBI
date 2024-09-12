// 2024 Fase 2: Dança de Formatura (https://neps.academy/br/exercise/2794)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, p, a, b;
	cin >> n >> m >> p;

	vector<int> colunas(m + 1), linhas(n + 1);
	iota(all(colunas), 0);
	iota(all(linhas), 0);

	while (p--) {
		char c;
		cin >> c >> a >> b;

		if (c == 'C') swap(colunas[a], colunas[b]);
		else swap(linhas[a], linhas[b]);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cout << (linhas[i] - 1) * m + colunas[j] << (j == m ? '\n' : ' ');
}
