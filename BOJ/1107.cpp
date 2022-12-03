#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool isBroken[10] = { false };
int ans;

void f(int x, int k) {
	if (x == 0) {
		if (isBroken[0] != true)
			ans = min(ans, 1 + n);
	}
	else {
		int result = x > n ? x - n : n - x;
		ans = min(ans, k + result);
	}
	for (int i = 0; i < 10; i++) {
		if (isBroken[i])continue;
		if (k == 0 && i == 0)continue;
		if (k < 6)
			f(x * 10 + i, k + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ans = n > 100 ? n - 100 : 100 - n;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		isBroken[x] = true;
	}

	f(0, 0);
	cout << ans;
}