#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m;
int cw[200001], ccw[200001];
int a[2][200000];
int dx[2] = { 1,-1 };
int dy[2] = { 1,1 };
int ans;

void f(int x, int y, int t) {
	if (t == 0) {
		t += cw[y] + 2 * m - 1;
	}
	else if (x == 0) {
		if (t < cw[y + 1] + y)
			t += cw[y + 1] + y - t;
		t += 2 * (m - 1 - y);
	}
	else {
		if (t < ccw[y + 1] + y)
			t += ccw[y + 1] + y - t;
		t += 2 * (m - 1 - y);
	}
	ans = min(t, ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> m;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cw[m - 1] = max(a[0][m - 1] - m + 2, a[1][m - 1] - m + 1);
		ccw[m - 1] = max(a[0][m - 1] - m + 1, a[1][m - 1] - m + 2);
		for (int i = m - 2; i > 0; i--) {
			cw[i] = max(a[0][i] - i + 1, a[1][i] - 2 * m + 2 + i);
			cw[i] = max(cw[i], cw[i + 1]);
			ccw[i] = max(a[0][i] - 2 * m + 2 + i, a[1][i] - i + 1);
			ccw[i] = max(ccw[i], ccw[i + 1]);
		}
		cw[0] = max(a[0][0], a[1][0] - 2 * m + 2);
		cw[0] = max(cw[0], cw[1]);
		ccw[0] = max(a[0][0] - 2 * m + 2, a[1][0]);
		ccw[0] = max(ccw[0], ccw[1]);

		pair<int, int>x = { 1,0 };
		int t = a[1][0] + 1;
		ans = 0x7fffffff;
		f(0, 0, 0);
		for (int i = 1; i < m; i++) {
			f(x.first, x.second, t);
			x.second += dy[i % 2];
			if (t >= a[x.first][x.second])t++;
			else t = a[x.first][x.second] + 1;
			x.first += dx[i % 2];
			if (t >= a[x.first][x.second])t++;
			else t = a[x.first][x.second] + 1;
		}
		cout << ans << '\n';
	}
}