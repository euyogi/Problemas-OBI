// 2024 Fase 2: Alfabeto Alienígena (https://neps.academy/br/exercise/2792)

#include <bits/stdc++.h>
using namespace std;

#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
	int k, n;
	cin >> k >> n;

	string a, b;
	cin >> a >> b;

	unordered_set<char> em_alienigena;
	for (char c : a)
		em_alienigena.emplace(c);

	for (char c : b)
		if (!found(c, em_alienigena)) {
			cout << "N\n";
			return 0;
		}

	cout << "S\n";
}
