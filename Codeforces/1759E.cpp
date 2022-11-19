#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int multi[5] = { 2,3,4,6,12 };
int green[5] = { 1,0,2,1,2 };
int blue[5] = { 0,1,0,1,1 };
int n;
ll a[200000];
int ans;

void search(int f, ll h, ll k, int g, int b, int c) {
	for (int i = f; i < n; i++) {
		if (a[i] >= h + k) {
			for (int j = 0; j < 5; j++) {
				if (green[j] <= g && blue[j] <= b) {
					if (a[i] < (h + k) * multi[j])
						search(i, h * multi[j], k * multi[j], g - green[j], b - blue[j], c);
				}
			}
			break;
		}
		c++;
		k += a[i] / 2;
	}
	ans = max(ans, c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll h;
		cin >> n >> h;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);

		ans = 0;
		search(0, h, 0, 2, 1, 0);

		cout << ans << '\n';
	}
}