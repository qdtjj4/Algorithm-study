#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int len;
		cin >> len;
		string s;
		cin >> s;
		int ans = 0;
		int n[10];

		for (int i = 0; i < len; i++) {
			fill(n, n + 10, 0);
			int size = 0;
			int big = 0;
			for (int j = i; j < i + 100; j++) {
				if (j >= len)break;
				if (n[s[j] - '0'] == 0)size++;
				n[s[j] - '0']++;
				big = max(big, n[s[j] - '0']);
				if (size >= big)ans++;
			}
		}

		cout << ans << '\n';
	}
}